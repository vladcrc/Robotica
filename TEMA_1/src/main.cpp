#include <Arduino.h>

const int redPin = 6;   
const int greenPin = 5; // Culorile led ului RGB
const int buttonStart = 2; // Buton de start
const int buttonStop = 3;  // Buton de stop
const int blueLedPins[] = {7, 8, 9, 10};//led urile albastre

unsigned int currentLed = 10; // icepem cu pin ul 10
bool processRunning = false;  

void flashBlueLed(int ledPin);
void flashAllBlueLeds();
void turnOffAllBlueLeds();
void resetProcess();

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(blueLedPins[i], OUTPUT);
    }

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    
    pinMode(buttonStart, INPUT_PULLUP);
    pinMode(buttonStop, INPUT_PULLUP);

    
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    // las led ul verde pornit 
} // stare initiala toate led urile stinde iar led ul RGB verde

void loop() {
    if (!processRunning) {
        digitalWrite(greenPin, HIGH);
        digitalWrite(redPin, LOW);
    } // aici verific ca led ul rgb sa se poata intoarce la culoarea verde in cazul in care procesul s a terminat

    if (digitalRead(buttonStart) == LOW) {
        processRunning = true;
        digitalWrite(greenPin, LOW);    
        digitalWrite(redPin, HIGH); //procesul incepe si fac led ul rgb rosu

        for (int cycle = 0; cycle < 4; cycle++) { 
            if (digitalRead(buttonStop) == LOW) { 
                resetProcess();
                break;
            }//la ficare ciclu de aprins led ul albastru verific la inceput si la sfarsit daca butonul 2 de stop a fost apasat

            int ledFlashCount = 0;
            while (ledFlashCount < 3 && currentLed >= 7) { 
                flashBlueLed(currentLed);  
                ledFlashCount++;
            }//aici am implementat efectul de flash ca butoanele sa se aprinda 

            if (currentLed >= 7) {
                digitalWrite(currentLed, HIGH); 
            }//tine ultimul led aprins 

            currentLed--;

            if (digitalRead(buttonStop) == LOW) { 
                delay(100);  
                if (digitalRead(buttonStop) == LOW) {
                    resetProcess();
                    break;
                }//verofic din nou daca butonul este apasat
            }
        }

        if (!processRunning) {
            flashAllBlueLeds();
        } else {
            flashAllBlueLeds();
        }//Aici folosesc iar efectul de flash daca am apasat butonul de stop sau s a terminat procesul

        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        processRunning = false; 
    }
}
void flashBlueLed(int ledPin) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
}

void flashAllBlueLeds() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            digitalWrite(blueLedPins[j], HIGH);
        }
        delay(300);
        for (int j = 0; j < 4; j++) {
            digitalWrite(blueLedPins[j], LOW);
        }
        delay(300);
    }
}

void turnOffAllBlueLeds() {
    for (int i = 0; i < 4; i++) {
        digitalWrite(blueLedPins[i], LOW);
    }
}//stinge lumina


void resetProcess() {
    currentLed = 10;
    processRunning = false;
    turnOffAllBlueLeds();
}