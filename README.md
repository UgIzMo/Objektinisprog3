# V1.2

  "Rule of Five" yra C++ programavimo taisyklė, kuri susijusi su specialiųjų narių valdymu objektuose, 
  kuriems reikia rankinio resursų valdymo (pvz., dinaminė atmintis ar ištekliai, kurie negali būti valdomi automatiškai). 
  Ši taisyklė apima penkis specialiuosius narius:

# Destructor (Destruktorius):

  ~Studentas() yra klasės destruktorius. 
  Jis naudojamas išvalyti resursus, kurie buvo skirti objekto veikimui.
  Destruktorius ~Studentas() išvalo namų darbų vektorių namuDarbai naudodamas clear() metodą.
  
# Copy Constructor (Kopijavimo konstruktorius):

  Studentas(const Studentas& other) yra kopijavimo konstruktorius. 
  Jis naudojamas sukurti naują objektą, kuris yra kopija esamo objekto.
  Konstruktorius Studentas(const Studentas& other) kopijuoja visus duomenis iš other objekto į naują Studentas objektą.

# Copy Assignment Operator (Kopijavimo priskyrimo operatorius):

  Studentas& operator=(const Studentas& other) yra kopijavimo priskyrimo operatorius. 
  Jis nukopijuoja vieno objekto turinį į kitą jau egzistuojantį objektą.
  Kopijavimo priskyrimo operatorius nukopijuoja visus duomenis iš other objekto į esamą Studentas objektą.

# Move Constructor (Perkėlimo konstruktorius):

  Studentas(Studentas&& other) noexcept yra perkėlimo konstruktorius. 
  Jis naudojamas perkelti resursus iš laikinojo (temporary) objekto į naują objektą.
  Perkėlimo konstruktorius Studentas(Studentas&& other) noexcept naudoja std::move() funkciją perkelti duomenis iš other objekto į naują Studentas objektą.

# Move Assignment Operator (Perkėlimo priskyrimo operatorius):

  Studentas& operator=(Studentas&& other) noexcept yra perkėlimo priskyrimo operatorius. 
  Jis naudojamas perkelti resursus iš laikinojo (temporary) objekto į jau egzistuojantį objektą.
  Perkėlimo priskyrimo operatorius Studentas& operator=(Studentas&& other) noexcept naudoja std::move() funkciją perkelti duomenis iš other objekto į esamą Studentas objektą.


# Įvesties ir išvesties operatoriai: 
  std::ostream& operator<<(std::ostream& os, const Studentas& student) - Išvedimo operatorius, leidžiantis išvesti studento duomenis. 
  std::istream& operator>>(std::istream& is, Studentas& student) - Įvedimo operatorius, leidžiantis nuskaityti studento duomenis.
  Šie metodai yra esminiai norint turėti galimybę dirbti su Studentas objektais išoriniuose šaltiniuose, pvz., failuose.

  Rankinis būdas:
  operator>> metodas leidžia rankiniu būdu nuskaityti duomenis iš srauto (pvz., iš std::cin).
  Naudojant šį metodą, galima tiesiogiai įvesti studento vardą, pavardę, egzamino rezultatą ir namų darbų rezultatus iš terminalo.

  Automatinis būdas:
  operator>> metodas taip pat gali būti naudojamas automatiškai nuskaitant duomenis iš kito šaltinio, pvz., iš failo.
  Leidžia nuskaitinėti iš failo ir užpildyti Studentas objektą duomenimis.

  Į ekraną:
  operator<< metodas leidžia išvesti Studentas objekto duomenis į ekraną (pvz., į std::cout).
  Išveda studento vardą, pavardę, egzamino rezultatą ir namų darbų rezultatus į terminalą.

  Į failą:
  operator<< metodas taip pat gali būti naudojamas išvesti duomenis į failą.
  Leidžia įrašyti Studentas objekto duomenis į failą, kurie vėliau gali būti perskaityti.

# Apibendrinant  
Perdengti operator<< ir operator>> metodai Studentas klasei suteikia universalumą duomenų įvedimui ir išvedimui iš įvairių šaltinių (įskaitant terminalą ir failus). Jie leidžia naudotis Studentas klase patogiai ir efektyviai, manipuliuojant duomenimis ir integruojant įvairius šaltinius duomenų apdorojimui.

| Failas               | Skaitymas (s)            | Rūšiavimas (s)           | Studentų skirstymas (s)       | Rūšiavimas ir skirstymas faile (s) |
|----------------------|--------------------------|--------------------------|-------------------------------|------------------------------------|
| studentas1000.txt    | 0.0036162                | 0.0000001                | 0.0000001                     | 0.00606105                         |
| studentas10000.txt   | 0.0065362                | 0.000000067              | 0.000000067                   | 0.0090507                          |
| studentas100000.txt  | 0.0375042                | 0.000000167              | 0.000000033                   | 0.0403738                          |
| studentas1000000.txt | 0.3171981                | 0.0000001                | 0.000000067                   | 0.3194002                          |

## V1.5

  Jame realizuota abstrakti bazinė klasė "Žmogus", kuri negali būti tiesiogiai naudojama objektams kurti, bei iš jos išvestinė (derived) klasė "Studentas".
  
  Struktūra
  studentas.h - Studento klasės deklaracija ir jos funkcijų aprašymai.
  zmogus.h - Abstrakčios klasės Žmogus deklaracija ir jos funkcijų aprašymai.
  studentas.cpp - Studento klasės metodų įgyvendinimas.
  
  Žmogus (Bazinė klasė): Abstrakti klasė, skirta apibūdinti bendrus žmogaus savybių modelio aspektus. Negalima tiesiogiai kurti "Žmogus" tipo objektų.
  Studentas (Išvestinė klasė): Klasė, paveldinti visas savybes iš "Žmogus" klasės. Realizuoja papildomus metodų ir savybių aspektus, specifinius studento vaidmeniui.

  Metodai
  Konstruktoriai ir destruktorius: Realizacija ir naudojimas klasėse.
  Kopijavimo metodai: Kaip veikia objekto kopijavimo metodai.
  Perkėlimo (move) metodai: Apie objekto perkėlimo metodų panaudojimą.
  Įvesties/išvesties metodai: Kaip duomenys yra įvedami ir išvedami iš klasės.
  
  Programa veikia pagal 1.2 versijos taisykles, kurios apibrėžia klasės veikimo logiką ir reikalavimus. Tai užtikrina veiksmingą ir korektišką funkcionalumą.

  Testavimas

    studentas1000.txt

      Skaitymas uztruko: 0.0109156s
      Rusiavimas uztruko: 0.0000004s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai1000.txt: 0.0139504s
      
      Skaitymas uztruko: 0.0036917s
      Rusiavimas uztruko: 0.0000003s
      Studentu skirstymas uztruko: 0.0000002s
      Rusiavimas ir skirstymas faile studentai1000.txt: 0.0066810s
      
      Skaitymas uztruko: 0.0036012s
      Rusiavimas uztruko: 0.0000005s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai1000.txt: 0.0060274s
  
    studentas10000.txt  

      Skaitymas uztruko: 0.0489442s
      Rusiavimas uztruko: 0.0000003s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai10000.txt: 0.0507379s
      
      Skaitymas uztruko: 0.0418828s
      Rusiavimas uztruko: 0.0000009s
      Studentu skirstymas uztruko: 0.0000005s
      Rusiavimas ir skirstymas faile studentai10000.txt: 0.0463429s
      
      Skaitymas uztruko: 0.0448249s
      Rusiavimas uztruko: 0.0000006s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai10000.txt: 0.0473987s

    studentas100000.txt

      Skaitymas uztruko: 0.3696679s
      Rusiavimas uztruko: 0.0000014s
      Studentu skirstymas uztruko: 0.0000002s
      Rusiavimas ir skirstymas faile studentai100000.txt: 0.3716144s
      
      Skaitymas uztruko: 0.3607576s
      Rusiavimas uztruko: 0.0000004s
      Studentu skirstymas uztruko: 0.0000002s
      Rusiavimas ir skirstymas faile studentai100000.txt: 0.3629284s
      
      Skaitymas uztruko: 0.3627148s
      Rusiavimas uztruko: 0.0000004s
      Studentu skirstymas uztruko: 0.0000002s
      Rusiavimas ir skirstymas faile studentai100000.txt: 0.3647824s

    studentas10000000.txt

      Skaitymas uztruko: 3.6412688s
      Rusiavimas uztruko: 0.0000005s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai1000000.txt: 3.6433200s
      
      Skaitymas uztruko: 3.5545791s
      Rusiavimas uztruko: 0.0000004s
      Studentu skirstymas uztruko: 0.0000002s
      Rusiavimas ir skirstymas faile studentai1000000.txt: 3.5565252s
      
      Skaitymas uztruko: 4.1009419s
      Rusiavimas uztruko: 0.0000003s
      Studentu skirstymas uztruko: 0.0000001s
      Rusiavimas ir skirstymas faile studentai1000000.txt: 4.1030884s

| Failas                | Skaitymas (s)         | Rūšiavimas(s)         | Studentų skirstymas (s)       | Rūšiavimas ir skirstymas faile (s) |
|-----------------------|-----------------------|-----------------------|-------------------------------|------------------------------------|
| studentas1000.txt     | 0.0064028             | 0.0000004             | 0.0000001                     | 0.0082196                          |
| studentas10000.txt    | 0.0455506             | 0.0000006             | 0.0000003                     | 0.0487932                          |
| studentas100000.txt   | 0.3640467             | 0.0000007             | 0.0000002                     | 0.3664417                          |
| studentas10000000.txt | 3.7652633             | 0.0000004             | 0.0000001                     | 3.7679779                          |

Skaitymo laikas:
Skaitymo laikas ženkliai didėja, kai padidėja failo dydis. 
Tai rodo, kad didesnių failų skaitymas užtrunka daugiau laiko, kas yra tikėtina dėl didesnio duomenų kiekio.

Rūšiavimo laikas:
Rūšiavimo laikas lieka stabiliai mažas nepaisant skirtingų failų dydžių, tai rodo, kad rūšiavimo operacija yra efektyvi ir nesąlygoja didelio duomenų apimties.

Studentų skirstymo laikas:
Studentų skirstymo laikas yra labai mažas ir pastovus visų failų dydžių atžvilgiu. 
Ši operacija atliekama labai efektyviai nepriklausomai nuo duomenų apimties.

Iš viso laikas rūšiavimui ir skirstymui faile:
Iš viso laikas rūšiavimui ir duomenų skirstymui faile žymiai didėja su didėjančiu failo dydžiu. 
Tai rodo, kad apdorojimo laikas proporcingai didėja su apdorojamų duomenų kiekiu.

Programos veikimas (failų apdorojimo atžvilgiu) proporcingai gerėja su didėjančiu failo dydžiu, ypač atsižvelgiant į skaitymo laiką ir bendrą apdorojimo laiką. 
Lentelės duomenys rodo, kad jūsų programa veikia pakankamai efektyviai, nes dauguma operacijų užtrunka labai trumpą laiką net su dideliais duomenų kiekiais. 

  Išvados:
  Atrodo, kad v1.5 paprastai turi šiek tiek mažesnį laiką duomenų skaitymui ir studentų pasiskirstymui visose studentų skaičiaus kategorijose. 
  Tačiau v1.2 kai kuriuose atveju turi šiek tiek mažesnį laiką duomenų rūšiavimui.
  Apskritai skirtumai tarp dviejų versijų yra santykinai nedideli, todėl pasirinkimas tarp jų gali nedidelės įtakos bendram veikimui ar duomenų interpretacijai.


# V2.0

  Iš pradžių buvo atlikta projekto v2.0 dokumentacija naudojantis doxygen pagalba. (file:///C:/Users/Asus/Desktop/II%20pusmetis/bandymai/v2.0/html/annotated.html)
  
  Doxygen yra įrankis, skirtas automatiškai generuoti dokumentaciją iš programinio kodo, rašyto daugiausia C++, bet palaikantis ir kitas programavimo kalbas. 
  Jo veikimo principas yra paremtas specialiai parašytomis komentarų žymėmis šalia kodo. 
  Šios žymės, paprastai pradedamos simboliu /**, leidžia rašyti struktūrizuotą ir išsamią dokumentaciją apie kodo funkcijas, klasės narius, modulius ir kintamuosius. 

  # Doxygen instrukcija
  
1. Pirma, eikite į oficialią Doxygen svetainę[https://www.doxygen.nl/manual/index.html]
2. Paspauskite atsisiuntimo mygtuką ir įdiekite programą pasirinktai operacinei sistemai
3. Sukonfigūruokite viską ir paleiskite Doxywizard
4. Dabar pasirinkite savo projekto aplanką, kuriame rodomi visi failai
5. Pavadinkite savo projektą, parašykite savo santrauką ir versiją, jei norite - pridėkite logotipą ir išsaugokite
6. Eikite į paleidimo langą ir spauskite Paleisti Doxygen mygtuką
7. Kai procesas baigsis, tiesiog eikite į savo projekto failus -> hmtl -> index.html
8. Atidarę jį turėsite visą savo dokumentaciją

  Svarbu paminėti, kad Doxygen dokumentacija reikalauja tik komentarų iš antraščių failų (.h). 
  
    Komentaro formatas: 
  Naudokite konkretų formatą komentarams, pripažintiems Doxygen, dažnai pradedant /** arba /*! norėdami nurodyti specialų komentarų bloką.
  
    Dokumentacijos žymės: 
  Naudokite specialias žymes kaip @brief, @param, @return, @see ir kt., kad suteiktumėte struktūrizuotą informaciją apie jūsų kodo elementus.

    Klasės Dokumentacija: 
  Dokumentuokite klases naudodami /** blokus virš klasės deklaracijos, pateikdami aprašymus, naudojimo pastabas ir visą atitinkamą informaciją.
    
    Funkcijų Dokumentacija: 
  Dokumentuokite funkcijas ir metodus su /** blokais prieš jų deklaracijas, įskaitant detalęs, tokias kaip parametrai, grąžinimo reikšmės ir naudojimo pavyzdžiai.

    Kintamųjų Dokumentacija: 
  Dokumentuokite kintamuosius naudodami /** blokus virš jų deklaracijų, nurodydami jų paskirtį, naudojimo gaires ir bet kokias papildomas detales.
  
    Grupavimas ir Organizavimas: 
  Susiejus susijusius elementus naudokite \defgroup ir \addtogroup komandas, kurios sukuria logiškas hierarchijas jūsų dokumentacijoje.
  
    Failo Lygio Dokumentacija: 
  Įtraukite failo lygio dokumentaciją naudodami /** blokus kiekviename šaltinio faile, aprašydami jo paskirtį, turinį ir naudojimą.
  
    Nuoseklumas ir Aiškumas: 
  Palaikykite nuoseklumą savo komentavimo stiliuje ir užtikrinkite aiškumą savo aprašymuose, padarydami ją lengvesnę vartotojams suprasti ir naršyti jūsų dokumentaciją.
  










  Unit testai: Unit testai yra skirti testuoti atskiras programos dalis (vienetas) norint įsitikinti, ar jos veikia teisingai. 
  Tai padeda užtikrinti, kad kiekviena programos dalis atlieka numatytas funkcijas ir veikia kaip tikimasi.
