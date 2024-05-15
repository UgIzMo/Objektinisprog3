# V3.0 dokumentacija

Vector konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector . Pasinaudodami std::vector konteinerio funkcijoms ir įsitikinkiname, kad gaunamr tuos pačius rezultatus naudojant Vector objektus.

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/b7847d42-4d77-49b2-8d5f-83dde90c01b5)

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/81818d6b-9e94-4e82-a1e6-b0db73005eee)

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/bad97f0d-99ef-423d-bd53-f3f910727535)


Pilnai ištestuotas sukurtas konteineris naudojant Unit Native Testing per Visual Studio.
Testai apima įvairias vektoriaus klasės funkcijas, užtikrinant jos teisingumą ir patikimumą.

Apie testus:
1. InitiallyEmpty: Patikrina, ar vektorius iš pradžių yra tuščias.
2. PushBack: Patikrina push_back metodą.
3. PopBack: Patikrina pop_back metodą.
4. Clear:  Patikrina clear metodą.
5. Capacity: Patikrina capacity metodą.
6. Iterators: Patikrina iteratorių funkcionalumą.
7. Sort: Patikrina sort metodą.
8. Reverse: Patikrina reverse metodą.
9. AccessByIndex: Patikrina elemento prieigą pagal indeksą.
10. AccessByIndexOutOfRange: Patikrina elemento prieigą už ribų.
11. CopyConstructor: Patikrina kopijos konstruktorių.
12. CopyAssignmentOperator: Patikrina kopijos priskyrimo operatorių.
13. MoveConstructor: Patikrina perkėlimo konstruktorių.
14. MoveAssignmentOperator: Patikrina perkėlimo priskyrimo operatorių.
15. Insert: Patikrina insert metodą.
16. Erase: Patikrina erase metodą.
17. IsSorted: Patikrina is_sorted metodą.
18. AccessInvalidIndex: Patikrina prieigą prie elementų naudojant netinkamus indeksus.
19. SortPerformance: Patikrina sort metodo našumą.
20. InsertAtDifferentPositions: Patikrina įterpimą į skirtingas pozicijas.
    
![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/4a9796be-1331-4d5e-9a96-7fe39c1b6474)

Įdomu tai, kad naudojant C++ Unit Testing platformą (CppUnitTest.h), galima lengvai kurti ir vykdyti testus tiesiogiai iš C++ kodo, todėl visi testai gali būti sukompiliuoti kartu su pagrindine programa. 
Tai palengvina testų kūrimą ir vykdymą, nes nereikia naudoti atskirų įrankių ar aplinkų bei iškart matome, kurie testai įvyko sėkmingai, o kurie ne.

# Setup.msi/exe failas programos diegimui į "C:/Program files/VU/Vardenis-Pavardenis" aplankalą

Instrukcijos diegimui [Jūsų programos pavadinimas]
Norėdami įdiegti [Jūsų programos pavadinimas], prašome laikytis šių žingsnių:
1. Parsisiųskite pateiktą Setup.msi arba Setup.exe failą.
2. Paleiskite parsisiųstą failą, kad pradėtumėte diegimo procesą.
3. Sekite ekrane pateiktas instrukcijas diegimo vedlyje.
4. Kai bus prašoma pasirinkti diegimo katalogą, pasirinkite C:/Program files/VU/Vardenis-Pavardenis.
5. Baigę diegimą, spustelėkite "Baigti" arba sekitės papildomų nurodymų.
6. Kai diegimas bus baigtas, galėsite paleisti [Jūsų programos pavadinimas] iš Starto meniu arba darbalaukio sutrumpinimo.
