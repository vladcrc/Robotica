![POZA_1_SET_UP_FIZIC](https://github.com/user-attachments/assets/ad1d4183-2a33-4310-a056-99cc60700dda)![WhatsApp Image 2024-10-22 at 10 34 51_37fd03ca](https://github.com/user-attachments/assets/97bef767-07dd-47ec-b0e0-0279e939d9bf)![WhatsApp Image 2024-10-22 at 10 34 51_5dfac260](https://github.com/user-attachments/assets/b80648d1-09b4-4362-996c-36978112bbde)1.1 Descriere
În această temă am simulat o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane.

1.2 Componente
4x LED-uri 
1x LED RGB
2x Butoane
8x Rezistoare (6x 330ohm, 2x 1K)
Breadboard
Linii de legătură

1.3 Detalii tehnice
Led-ul RGB reprezintă disponibilitatea stației. Dacă stația este liberă led-ul va fi verde, iar dacă stația este ocupată se va face roșu.
Led-urile simple reprezintă gradul de încărcare al bateriei, pe care îl vom simula printr-un loader progresiv (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%).
Loader-ul se încărca prin aprinderea succesivă a led-urilor, la un interval fix de 3s.
Apăsarea scurtă a butonului de start va porni încărcarea. Apăsarea acestui buton în timpul încărcării nu va face nimic.
Apăsarea lungă a butonului de stop va opri încărcarea forțat și va reseta stația la starea liberă. Apăsarea acestui buton cat timp stația este liberă nu va face nimic.

link video cu functionalitatea montajului fizic : https://www.youtube.com/shorts/b96_d3jiV5M?si=XeKxYpVMCGaajPPN
