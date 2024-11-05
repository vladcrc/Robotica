#include <TimerOne.h>
#include <avr/interrupt.h>


const int redPin = 10;// Pini led RGB
const int greenPin = 11;
const int bluePin = 12;
const int startStopButtonPin = 2;// Pini butoane
const int difficultyButtonPin = 3;
enum JOC { IDLE, COUNTDOWN, PLAYING, FINISHED };
JOC gameState = IDLE;
enum Difficulty { EASY, MEDIUM, HARD };
Difficulty difficulty = EASY;
unsigned long roundStartTime;
int correctWords = 0;
unsigned long roundDuration; 
unsigned long lastDifficultyPress = 0; // Timestamp buton

String words[] = {
    "mar", "pisica", "leu", "alb", "inginer", "telefon", 
    "carte", "ceas", "frigider", "padure", "copac", "zapada",
    "ploaie", "soare", "bicicleta", "barca", "camion", "elicopter",
    "satelit", "racheta", "bucurie", "tristete", "fericire", "teama",
    "vulcan", "camp", "scaun", "tastatura", "masina", "vanzator"
};

const int numWords = sizeof(words) / sizeof(words[0]); 
String currentWord;

void setLED(int r, int g, int b);
void StartStop();
void dificultate();
void countdown();
void play();
void final();
void startStopISR();
void difficultyISR();

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(startStopButtonPin, INPUT_PULLUP);
  pinMode(difficultyButtonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(startStopButtonPin), startStopISR, FALLING);//interupere butoane
  attachInterrupt(digitalPinToInterrupt(difficultyButtonPin), difficultyISR, FALLING);
  setLED(255, 255, 255);//setez led ul sa fie alb
}

void loop() {
  switch (gameState) {
    case COUNTDOWN:
      countdown();
      break;
    case PLAYING:
      play();
      break;
    case FINISHED:
      final();
      break;
    case IDLE:
    default:
      break;
  }
}

void StartStop() {
  if (gameState == IDLE) {
    gameState = COUNTDOWN;
  } else if (gameState == PLAYING || gameState == FINISHED) {
    gameState = IDLE;
    setLED(255, 255, 255); // revin la cul alba
    currentWord = "";           
  }
}

void countdown() {
  setLED(255, 255, 255); 
  for (int i = 3; i > 0; i--) {
    Serial.println(i);
    delay(1000);
  }
  gameState = PLAYING;
  roundStartTime = millis();
  correctWords = 0;

  switch (difficulty) {// Setez in functie de dificultate nr de sec
    case EASY:
      roundDuration = 30000; // 30 sec
      break;
    case MEDIUM:
      roundDuration = 20000; // 20 sec
      break;
    case HARD:
      roundDuration = 10000; // 10 sec
      break;
  }
}

void play() {
  unsigned long currentTime = millis();
  if (currentTime - roundStartTime >= roundDuration) {
    gameState = FINISHED;
    return;
  }

  
  if (currentWord == "") {// verific daca se afiseaza un cuv
    int randomIndex = random(numWords);
    currentWord = words[randomIndex];
    Serial.print("Type the word: ");
    Serial.println(currentWord);
  }

  
  if (Serial.available() > 0) {// Verific daca s-a scris vreun cuvant
    String input = Serial.readStringUntil('\n');
    input.trim(); // Nu iau in considerare spatiile goale

    if (input.equalsIgnoreCase(currentWord)) {
      setLED(0, 255, 0); //verde
      correctWords++;
      delay(500);
      setLED(255, 255, 255); // alb
    } else {
      setLED(0, 0, 255); // rosu
      delay(500);
      setLED(255, 255, 255); 
    }
     currentWord = ""; //Cuvant nou
  }
}

void final() {
  setLED(255, 255, 255); //alb pt repaus
  Serial.print("Round finished! Correct words: ");
  Serial.println(correctWords);
  currentWord = ""; // resetez 
  correctWords = 0;           
  gameState = IDLE;           
}

void dificultate() {
  switch (difficulty) {
    case EASY:
      difficulty = MEDIUM;
      Serial.println("Medium mode on!");
      break;
    case MEDIUM:
      difficulty = HARD;
      Serial.println("Hard mode on!");
      break;
    case HARD:
      difficulty = EASY;
      Serial.println("Easy mode on!");
      break;
  }
}

void startStopISR() {//INTRERUP PT START/STOP 
  StartStop();
}

void difficultyISR() {
  unsigned long currentTime = millis();
  if (currentTime - lastDifficultyPress > 200) { 
    dificultate();
    lastDifficultyPress = currentTime; 
  }
}

void setLED(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}