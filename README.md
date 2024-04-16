  V1.2

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

Testavimas 

    studentas10000.txt
  
  Skaitymas uztruko: 0.0113764s
  Rusiavimas uztruko: 0.0000000s
  Studentu skirstymas uztruko: 0.0000000s
  Rusiavimas ir skirstymas faile studentai1000.txt: 0.0150300s

  Skaitymas uztruko: 0.0040083s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai1000.txt: 0.0069164s

  Skaitymas uztruko: 0.0032240s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai1000.txt: 0.0052057s
  
    studentas100000.txt
    
  Skaitymas uztruko: 0.0417487s
  Rusiavimas uztruko: 0.0000002s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai10000.txt: 0.0437969s
  
  Skaitymas uztruko: 0.0358946s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000000s
  Rusiavimas ir skirstymas faile studentai10000.txt: 0.0379611s
  
  Skaitymas uztruko: 0.0348692s
  Rusiavimas uztruko: 0.0000002s
  Studentu skirstymas uztruko: 0.0000000s
  Rusiavimas ir skirstymas faile studentai10000.txt: 0.0393635s

    studentas1000000.txt

  Skaitymas uztruko: 0.3212307s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai100000.txt: 0.3232132s
  
  Skaitymas uztruko: 0.3127440s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai100000.txt: 0.3153796s
  
  Skaitymas uztruko: 0.3176197s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000000s
  Rusiavimas ir skirstymas faile studentai100000.txt: 0.3196079s

    studentas10000000.txt

  Skaitymas uztruko: 3.0777628s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai1000000.txt: 3.0798064s
  
  Skaitymas uztruko: 3.1251866s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai1000000.txt: 3.1275145s
  
  Skaitymas uztruko: 3.1296369s
  Rusiavimas uztruko: 0.0000001s
  Studentu skirstymas uztruko: 0.0000001s
  Rusiavimas ir skirstymas faile studentai1000000.txt: 3.1318662s

| Failas               | Skaitymas (s)            | Rūšiavimas (s)           | Studentų skirstymas (s)       | Rūšiavimas ir skirstymas faile (s) |
|----------------------|--------------------------|--------------------------|-------------------------------|------------------------------------|
| studentas1000.txt    | 0.0036162                | 0.0000001                | 0.0000001                     | 0.00606105                         |
| studentas10000.txt   | 0.0065362                | 0.000000067              | 0.000000067                   | 0.0090507                          |
| studentas100000.txt  | 0.0375042                | 0.000000167              | 0.000000033                   | 0.0403738                          |
| studentas1000000.txt | 0.3171981                | 0.0000001                | 0.000000067                   | 0.3194002                          |

Skaitymo laikas: 
Didėja su failo dydžiu. Programa efektyviai nuskaito duomenis, bet su didesniais failais laikas ilgėja.

Rūšiavimo laikas: 
Labai mažas, net su dideliais failais. Rūšiavimas veikia efektyviai.

Skirstymo laikas: 
Taip pat labai mažas net su dideliais failais. Duomenų analizė ir skirstymas veikia efektyviai.

Rūšiavimo ir skirstymo faile laikas: 
Proporcingai didėja su failo dydžiu. Su didesniais failais šie veiksmai gali trukti ilgiau.

Iš šių išvadų matyti, kad programa gerai veikia su vidutinio dydžio ir dideliais failais. 
Jei reikia gerinti veikimą su didesniais duomenų kiekiais, galima optimizuoti rūšiavimo ir skirstymo procesus.


