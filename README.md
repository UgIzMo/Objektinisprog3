  V1.5

  Ši programa yra skirta valdyti studentų duomenis. Vietoje vienos klasės Studentas buvo sukurtos dvi klases: abstrakti bazinė klasė Zmogus ir iš jos paveldėta išvestinė klasė Studentas.


  Žmogus klasė 
  Zmogus yra abstrakti bazinė klasė, skirta apibrėžti bendrus žmogaus savybes ir veiksmus. 
  Iš šios klasės negalima sukurti objektų tiesiogiai, tačiau ji yra naudojama kaip pagrindas Studentas klasės paveldėjimui. 
  
  Metodai 
  virtual int getAge() const = 0; - šis metodas grąžina žmogaus amžių. 
  virtual std::string getName() const = 0; - šis metodas grąžina žmogaus vardą ir pavardę. 
  
  Studentas klasė 
  Studentas yra Zmogus išvestinė klasė, kuri paveldi bendras savybes ir veiksmus iš Zmogus bazinės klasės. 
  Ši klasė papildomai turi studento specifinius metodus ir savybes. 
  Savybės 
  std::string vardas - studento vardas. 
  std::string pavarde - studento pavardė. 
  std::vector<int> namuDarbai - studento namų darbų rezultatų vektorius. 
  int egzaminas - studento egzamino rezultatas. 
  
  Metodai Konstruktorius: 
  Studentas(), Studentas(const std::string& vardas, const std::string& pavarde). 
  virtual int getAge() const override; - grąžina studento amžių. 
  virtual std::string getName() const override; - grąžina studento vardą ir pavardę. 
  
  Getteriai ir setteriai: setVardas, getVardas, setPavarde, getPavarde, setNamuDarbai, getNamuDarbai, setEgzaminas, getEgzaminas. 
  
  Skaičiavimo metodai: skaiciuotiVidurki, skaiciuotiMediana, skaiciuotiGalutini. 
  
  Randomizacijos metodai: atsitiktiniai, atsitiktiniaiStudentai. 
  
  Išvesties ir įvesties operatoriai: operator<<, operator>>. 
  
  Veikimo logika 
  Programa veikia pagal 1.2 versijos reikalavimus, įskaitant visus pridėtus metodus ir jų veikimo logiką. 
  Studento klasė tinkamai paveldi Zmogus bazinės klasės metodus ir palaiko 1.2 versijoje realizuotą penkių metodų taisyklę.
