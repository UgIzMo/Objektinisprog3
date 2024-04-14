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
