# V3.0 dokumentacija

Vector konteineris veikia (funkcionalumo prasme) lygiai taip pat, kaip ir std::vector. Pasinaudodami std::vector konteinerio funkcijoms ir įsitikinkiname, kad gauname tuos pačius rezultatus naudojant Vector objektus.

Trumpai tariant, ši repozitorija yra dinaminio masyvo įgyvendinimas, panašus į std::vector, parašytas C++ kalba. 
Vector klasės šablonas suteikia lankstų masyvą, kuris gali dinamiškai didėti pridedant elementus. 
Jis palaiko įvairias funkcijas, nuo pagrindinių operacijų iki pažangaus funkcionalumo, tokio kaip rūšiavimas ir bandymų vykdymas.

Pagrindinės funkcijos, kurios yra naudojamos ir labiausiai paplitusios:
 1. Dinaminis dydžio keitimas: Automatiškai didėja dydis pridedant elementus.
 2. Iteratoriai: Suteikia tiek įprastinius, tiek konstantinius iteratorius elementų prieigai.
 3. Elementų prieiga: Palaiko operatorius[], front(), back() ir kitus prieigos metodus.
 4. Modifikatoriai: Įtraukia push_back(), pop_back(), insert(), erase(), clear(), reserve() ir resize() metodus.
 5. Algoritmai: Metodai rūšiavimui, atvirkštinimui ir dublikatų radimui.
 6. Naudingos funkcijos: Bandymai našumo matavimui ir elementų sukimo funkcijos.

# Pavyzdžiai
  NR. 1 Šis bandymas demonstruoja pagrindines operacijas, tokias kaip elementų pridėjimas, pašalinimas ir prieiga.

Kodas:

    #include "vector.h"
    #include <iostream>
    
    int main() {
        Vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
    
        std::cout << "Vector: " << vec << std::endl;
    
        vec.pop_back();
        std::cout << "After pop_back: " << vec << std::endl;
    
        vec[0] = 15;
        std::cout << "After modifying first element: " << vec << std::endl;
    
        return 0;
    }

Išvedimas turėtų gautis toks:
   Vector: [10, 20, 30]
   After pop_back: [10, 20]
   After modifying first element: [15, 20]


 NR. 2 Šis bandymas pristato pažangias funkcijas, tokiu kaip rūšiavimas, atvirkštinimas ir dublikatų paieška.

Kodas:

    #include "vector.h"
    #include <iostream>
    
    int main() {
        Vector<int> vec;
        vec.push_back(3);
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(2);
    
        vec.sort();
        std::cout << "After sorting: " << vec << std::endl;
    
        vec.reverse();
        std::cout << "After reversing: " << vec << std::endl;
    
        try {
            int duplicate = vec.first_duplicate();
            std::cout << "First duplicate: " << duplicate << std::endl;
        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    
        return 0;
    }

 Išvedimas turėtų gautis toks:
  After sorting: [1, 2, 2, 3]
  After reversing: [3, 2, 2, 1]
  First duplicate: 2


 NR.3 Šis bandymas iliustruoja kopijavimo ir perkėlimo konstruktoriaus bei priskyrimo operatorių veikimą.

Kodas:

    #include "vector.h"
    #include <iostream>
    
    int main() {
        Vector<int> vec1;
        vec1.push_back(1);
        vec1.push_back(2);
        vec1.push_back(3);
    
        Vector<int> vec2 = vec1; // Copy constructor
        Vector<int> vec3 = std::move(vec1); // Move constructor
    
        std::cout << "vec2 (after copy): " << vec2 << std::endl;
        std::cout << "vec3 (after move): " << vec3 << std::endl;
    
        return 0;
    }

 Išvedimas turėtų gautis toks:
  vec2 (after copy): [1, 2, 3]
  vec3 (after move): [1, 2, 3]

  KITI galimi testai:

1. Testas su `push_back` ir `size`:

       Vector<int> vec;
       vec.push_back(1);
       vec.push_back(2);
       assert(vec.size() == 2);
   
3. Testas `pop_back` ir `empty`:

       Vector<int> vec;
       vec.push_back(1);
       vec.pop_back();
       assert(vec.empty());
   
3. Bandymas elementų prieigos su operator[] metodu:

       Vector<int> vec;
       vec.push_back(10);
       assert(vec[0] == 10);

4. Testas `sort` methodų:

       Vector<int> vec;
       vec.push_back(3);
       vec.push_back(1);
       vec.push_back(2);
       vec.sort();
       assert(vec[0] == 1 && vec[1] == 2 && vec[2] == 3);


# Vector klasės našumo palyginimas su std::vector

 Matuojame Vector klasės našumą palyginant su `std::vector`. Laikai yra išreikšti sekundėmis ir apskaičiuoti naudojant vidurkį iš kelių bandymų.

| Elementų skaičius | std::vector laikas (s) | Vector laikas (s) |
|-------------------|------------------------|-------------------|
| 10000             | 0.000439               | 0.000201          |
| 100000            | 0.004602               | 0.001430          |
| 1000000           | 0.043796               | 0.015032          |
| 10000000          | 0.328206               | 0.141058          |
| 100000000         | 3.406001               | 1.419940          |


![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/b7847d42-4d77-49b2-8d5f-83dde90c01b5)

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/81818d6b-9e94-4e82-a1e6-b0db73005eee)

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/bad97f0d-99ef-423d-bd53-f3f910727535)

Išvados

- Vector klasė demonstruoja gerokai didesnį našumą nei `std::vector`, ypač su dideliu elementų skaičiumi.
- Vector klasė pasižymi greitesniu veikimu užpildant vektorius naudojant `push_back()` funkciją, palyginti su `std::vector`.
- Naudojant Vector klasę, galima pastebėti reikšmingą našumo padidėjimą, ypač kai vektoriaus dydis didėja.
- Vector klasė gali būti patrauklus pasirinkimas, norint pagerinti programos veikimo efektyvumą, ypač dirbant su dideliais duomenų kiekiais.
  [Tačiau reikėtų atsižvelgti į tai, kad našumo skirtumai gali kisti priklausomai nuo specifinių naudojamų operacijų ir aplinkos.]


# Pilnai ištestuotas sukurtas konteineris naudojant Unit Native Testing per Visual Studio.
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

# Plačiau apie Unit testus: 
  Unit testai yra skirti testuoti atskiras programos dalis (vienetas) norint įsitikinti, ar jos veikia teisingai. 
  Tai padeda užtikrinti, kad kiekviena programos dalis atlieka numatytas funkcijas ir veikia kaip tikimasi.

  Naudojau Visual Studio 2022 Unit testavimui, nes tai vienas iš geriausių integruotų kūrimo aplinkų šiam darbui. 
  Taip pat galite naudoti JetBrains.
  
  Pasirinkau native framework.

  Projekto failo paruošimas
  
  1. Pirmiausia atidarykite "Visual Studio"
  2. Spauskite "Create new project"
  3. Pasirinkite "Native Unit Testing", nes "VS" atliks visus reikiamus veiksmus, sukurs ir redaguos būtinus jūsų savybių failus
  4. Kai projektas sukurtas, eikite į Projekc -> {failo pavadinimas} properties -> C/C++ -> All functions -> Precompiled Header ir pakeiskite į "Not Using Precompiled Headers"
  5. Dabar spauskite "Apply" ir "Ok"
  6. Dabar spauskite "Projektas" ir pridėkite esamus failus, kuriuos norite testuoti
     
  Paskutiniai kodavimo pakeitimai
  Kai tai padarysite, tiesiog parašykite naujas funkcijas, kurios testuos tai, ko jums reikia
  Kai viskas baigta, eikite į "Test" ir atidarykite "Test Explorer"
  Dabar tiesiog spauskite "Paleisti visus testus" ir jūs tai turėsite

# Doxygen instrukcija
  
1. Pirma, eikite į oficialią Doxygen svetainę[https://www.doxygen.nl/manual/index.html]
2. Paspauskite atsisiuntimo mygtuką ir įdiekite programą pasirinktai operacinei sistemai
3. Sukonfigūruokite viską ir paleiskite Doxywizard
4. Dabar pasirinkite savo projekto aplanką, kuriame rodomi visi failai
5. Pavadinkite savo projektą, parašykite savo santrauką ir versiją, jei norite - pridėkite logotipą ir išsaugokite
6. Eikite į paleidimo langą ir spauskite Paleisti Doxygen mygtuką
7. Kai procesas baigsis, tiesiog eikite į savo projekto failus -> hmtl -> index.html
8. Atidarę jį turėsite visą savo dokumentaciją

Galimi dokumentacijos formatai:
  HTML: Rasta v3.0/html kataloge. Atidarykite index.html failą peržiūrai.
  LaTeX: Rasta v3.0/latex kataloge. Galima sukompiliuoti į PDF naudojant LaTeX redaktorių.
  PDF: Ankstesnis PDF dokumentas yra prieinamas saugykloje patogiam naudojimui.

# Setup.msi/exe failas programos diegimui į "C:/Program files/VU/Vardenis-Pavardenis" aplankalą

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/3b900072-17cf-41e6-bd2e-e46aed480a16)

Parsisiunčiau Setup.exe failą naudodama Inno Setup Compiler iš https://inno-setup-compiler.en.lo4d.com/windows. 
(Siunčiantis buvo problemų su Avira antivirusine, nes gavau įspėjimą dėl viruso, bet viską atkūrus, viskas veikė ir virusai neaplankė.)
Taip sukūriau .iss scenarijų. 

![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/c7e0504e-f6bf-418b-855f-307db8f9601e)

Setup.exe failas įdiegtas į C:/Program files/VU/Laboratorinis darbas aplanką.
Taip pat buvo sueiktos administratoriaus teisės, buvo iššokęs pranešimo geltonas laukelis.

Instrukcijos diegimui [Jūsų programos pavadinimas]
Norėdami įdiegti [Jūsų programos pavadinimas], prašome laikytis šių žingsnių:
1. Parsisiųskite pateiktą failą.
2. Paleiskite parsisiųstą failą, kad pradėtumėte diegimo procesą.
3. Sekite ekrane pateiktas instrukcijas diegimo vedlyje.
4. Kai bus prašoma pasirinkti diegimo katalogą, pasirinkite C:/Program files/VU/Vardenis-Pavardenis.
5. Baigę diegimą, spustelėkite "Baigti" arba sekitės papildomų nurodymų.
6. Kai diegimas bus baigtas, galėsite paleisti [Jūsų programos pavadinimas] iš Starto meniu arba darbalaukio sutrumpinimo.

Po viso šio žingsnio matome gražiai iššokanti meniu:
![image](https://github.com/UgIzMo/Objektinisprog3/assets/152986822/77bf0e58-6ae8-40d6-a6eb-4cd0b9d6c92c)
