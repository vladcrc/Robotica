1.1 Descriere
În această temă am simulat o stație de încărcare pentru un vehicul electric, folosind mai multe LED-uri și butoane.

2. Componente
4x LED-uri 
1x LED RGB
2x Butoane
8x Rezistoare (6x 330ohm, 2x 1K)
Breadboard
Linii de legătură

3. Detalii tehnice
Led-ul RGB reprezintă disponibilitatea stației. Dacă stația este liberă led-ul va fi verde, iar dacă stația este ocupată se va face roșu.
Led-urile simple reprezintă gradul de încărcare al bateriei, pe care îl vom simula printr-un loader progresiv (L1 = 25%, L2 = 50%, L3 = 75%, L4 = 100%).
Loader-ul se încărca prin aprinderea succesivă a led-urilor, la un interval fix de 3s.
Apăsarea scurtă a butonului de start va porni încărcarea. Apăsarea acestui buton în timpul încărcării nu va face nimic.
Apăsarea lungă a butonului de stop va opri încărcarea forțat și va reseta stația la starea liberă. Apăsarea acestui buton cat timp stația este liberă nu va face nimic.

4. Poze ale montajului fizic
![WhatsApp Image 2024-10-22 at 10 34 51_c06cb2e7](https://github.com/user-attachments/assets/fbf7fa1e-cde6-48d0-b1ed-b733134ca9e9)
![WhatsApp Image 2024-10-22 at 10 34 51_c50adb66](https://github.com/user-attachments/assets/47ef08c9-5013-494f-879c-064a6cbd189d)

5.Link video cu functionalitatea montajului fizic : 
https://www.youtube.com/shorts/b96_d3jiV5M?si=XeKxYpVMCGaajPPN

6.Schema electrică Wokwi
![TEMA_1_ROB](https://github.com/user-attachments/assets/59ce0108-8e31-46a8-baec-d827d9f36213)


