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
