2.1 Componente

Arduino UNO (ATmega328P microcontroller)
1x LED RGB (pentru a semnaliza dacă cuvântul corect e scris greșit sau nu)
2x Butoane (pentru start/stop rundă și pentru selectarea dificultății)
5x Rezistoare (3x 220/330 ohm, 2x 1000 ohm)
Breadbord
Fire de legătură

2.2 Detalii tehnice

LED RGB - Indicator de stare:
În starea de repaus, LED-ul va avea culoarea albă.
La apăsarea butonului de start, LED-ul va clipi timp de 3 secunde, indicând o numărătoare inversă până la începerea rundei.
În timpul unei runde: LED-ul va fi verde dacă textul introdus este corect și va deveni roșu în caz de greșeală.

Butonul Start/Stop:
Modul de repaus: Dacă jocul este oprit, apăsarea butonului inițiază o nouă rundă după o numărătoare inversă de 3 secunde.
În timpul unei runde: Dacă runda este activă, apăsarea butonului o va opri imediat.

Butonul de dificultate:
Butonul de dificultate controlează viteza cu care apar cuvintele și poate fi folosit doar în starea de repaus.
La fiecare apăsare, dificultatea se schimbă ciclind între: (Easy, Medium, Hard).
La schimbarea dificultății, se trimite un mesaj prin serial: “Easy/Medium/Hard mode on!”.

Generarea cuvintelor:
Se va crea un dicționar de cuvinte.
În timpul unei runde, cuvintele vor fi afișate în terminal într-o ordine aleatorie.
Dacă cuvântul curent a fost scris corect, un cuvânt nou va fi afișat imediat. Dacă nu, un nou cuvânt va apărea după intervalul de timp stabilit în funcție de dificultate.

2.3 Flow
Jocul este în repaus. LED-ul RGB are culoarea albă.
Se alege dificultatea jocului folosind butonul de dificultate, iar în terminal va apărea “Easy/Medium/Hard mode on!”.
Se apasă butonul de start/stop.
LED-ul clipește timp de 3 secunde, iar în terminal se va afișa numărătoarea înversă: 3, 2, 1.
LED-ul devine verde și încep să apară cuvinte de tastat.
La tastarea corectă, următorul cuvânt apare imediat. Dacă nu se tasteaza cuvântul în timpul stabilit de dificultate, va apărea un nou cuvânt.
O greșeală face LED-ul să devină roșu. Pentru a corecta cuvântul, se va folosi tasta BackSpace.
Dupa 30 de secunde, runda se termină, iar în terminal se va afișa scorul: numărul total de cuvinte scrise corect.
Jocul se poate opri oricând cu butonul de start/stop.

2.4 Poze ale set-up 
![WhatsApp Image 2024-11-05 at 02 13 02_5adf2c5f](https://github.com/user-attachments/assets/338c86b6-f8b3-42d4-af61-31877fdbea24)
![WhatsApp Image 2024-11-05 at 02 13 02_11be2b42](https://github.com/user-attachments/assets/d7b43fd7-6697-42dd-a3fc-1c6eb50f1e3d)

2.5 Schema ![WhatsApp Image 2024-11-04 at 09 45 52_68f546b9](https://github.com/user-attachments/assets/8553320e-549e-4c26-b3da-52bd6644b9d4)


2.6 Link youtobe functionalitate https://www.youtube.com/shorts/a4BiUybRoBE
