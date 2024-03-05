Ši programa yra papildyta studentų failų generavimo funkcija. Šiuos failus galima nuskaityti, suskirstyti pagal kategoriją (į vargšiukus ir į kietiakus), išruošiuoti bei išvesti į du failus: vargsiukai.txt ir kietiakai.txt.
Buvo atlikti testavimai, tai yra apačioje pateikti tyrimai. Taip patikrinau kodo veikimą ir palyginau laikus. Laikai su kiekvienu kartu vis skyrėsi.

Programos veikimo greičio (spartos) analizė v0.4:
Programoje matomas vaizdas:

1 tyrimas: 
    
    1 bandymas:
    Sekmingai sugeneruotas failas: studentai1000.txt. Failo generavimas uztruko: 0.0230689 sekundziu. 
    Sekmingai sugeneruotas failas: studentai10000.txt. Failo generavimas uztruko: 0.0685928 sekundziu. 
    Sekmingai sugeneruotas failas: studentai100000.txt. Failo generavimas uztruko: 1.24731 sekundziu. 
    Sekmingai sugeneruotas failas: studentai1000000.txt. Failo generavimas uztruko: 17.8129 sekundziu.
    Sekmingai sugeneruotas failas: studentai10000000.txt. Failo generavimas uztruko: 157.417 sekundziu. 
    Failu generavimas uztruko: 176.573 sekundziu.

    2 bandymas:
    Sekmingai sugeneruotas failas: studentai1000.txt. Failo generavimas uztruko: 0.0160892 sekundziu. 
    Sekmingai sugeneruotas failas: studentai10000.txt. Failo generavimas uztruko: 0.0972604 sekundziu. 
    Sekmingai sugeneruotas failas: studentai100000.txt. Failo generavimas uztruko: 1.56105 sekundziu. 
    Sekmingai sugeneruotas failas: studentai1000000.txt. Failo generavimas uztruko: 15.3868 sekundziu. 
    Sekmingai sugeneruotas failas: studentai10000000.txt. Failo generavimas uztruko: 147.033 sekundziu. 
    Failu generavimas uztruko: 164.1 sekundziu.

    3 bandymas:
    Sekmingai sugeneruotas failas: studentai1000.txt. Failo generavimas uztruko: 0.0176659 sekundziu.
    Sekmingai sugeneruotas failas: studentai10000.txt. Failo generavimas uztruko: 0.163713 sekundziu.
    Sekmingai sugeneruotas failas: studentai100000.txt. Failo generavimas uztruko: 0.744931 sekundziu.
    Sekmingai sugeneruotas failas: studentai1000000.txt. Failo generavimas uztruko: 15.3988 sekundziu.
    Sekmingai sugeneruotas failas: studentai10000000.txt. Failo generavimas uztruko: 169.859 sekundziu. 
    Failu generavimas uztruko: 186.191 sekundziu.

    4 bandymas:
    Sekmingai sugeneruotas failas: studentai1000.txt. Failo generavimas uztruko: 0.016813 sekundziu.
    Sekmingai sugeneruotas failas: studentai10000.txt. Failo generavimas uztruko: 0.0888811 sekundziu.
    Sekmingai sugeneruotas failas: studentai100000.txt. Failo generavimas uztruko: 1.75883 sekundziu.
    Sekmingai sugeneruotas failas: studentai1000000.txt. Failo generavimas uztruko: 14.8308 sekundziu.
    Sekmingai sugeneruotas failas: studentai10000000.txt. Failo generavimas uztruko: 171.015 sekundziu. 
    Failu generavimas uztruko: 187.715 sekundziu.

    5 bandymas:
    Sekmingai sugeneruotas failas: studentai1000.txt. Failo generavimas uztruko: 0.0176368 sekundziu. 
    Sekmingai sugeneruotas failas: studentai10000.txt. Failo generavimas uztruko: 0.0641948 sekundziu. 
    Sekmingai sugeneruotas failas: studentai100000.txt. Failo generavimas uztruko: 2.05024 sekundziu. 
    Sekmingai sugeneruotas failas: studentai1000000.txt. Failo generavimas uztruko: 15.1384 sekundziu. 
    Sekmingai sugeneruotas failas: studentai10000000.txt. Failo generavimas uztruko: 140.774 sekundziu. 
    Failu generavimas uztruko: 158.049 sekundziu.

    Vidurkis:
    studentai1000.txt = 0.01845496 s
    studentai10000.txt  = 0.09612818 s
    studentai100000.txt = 1.472272 s
    studentai1000000.txt = 15.51374 s
    studentai10000000.txt = 157.8196 s 
    Visų failų = 174.9256 s

2 tyrimas:

    studentai1000.txt:
    Nuskaitymas uztruko: 0.0034581 sekundziu
    Suskirstymas i vargsiukai.txt ir kietiakai.txt uztruko: 0.000647 sekundziu.
    Rusiavimas uztruko: 1.67575 sekundziu.
    Isvedimas i faila vargsiukai.txt: 0.0099455
    Isvedimas i faila kietiakai.txt: 0.0090377
    Visas sugaistas laikas: 1.69884 s

    studentai10000.txt:
    Nuskaitymas uztruko: 0.0482631 sekundziu
    Suskirstymas i vargsiukai.txt ir kietiakai.txt uztruko: 0.0058023 sekundziu.
    Rusiavimas uztruko: 1.841 sekundziu.
    Isvedimas i faila vargsiukai.txt: 0.0801023
    Isvedimas i faila kietiakai.txt: 0.0470074
    Visas sugaistas laikas: 2.02218 s

    studentai100000.txt:
    Nuskaitymas uztruko: 0.371336 sekundziu
    Suskirstymas i vargsiukai.txt ir kietiakai.txt uztruko: 0.0638432 sekundziu.
    Rusiavimas uztruko: 5.21038 sekundziu.
    Isvedimas i faila vargsiukai.txt: 0.574922
    Isvedimas i faila kietiakai.txt: 0.908522
    Visas sugaistas laikas: 7.12901 s

    studentai1000000.txt:
    Nuskaitymas uztruko: 3.68732 sekundziu
    Suskirstymas i vargsiukai.txt ir kietiakai.txt uztruko: 0.610123 sekundziu.
    Rusiavimas uztruko: 6.36201 sekundziu.
    Isvedimas i faila vargsiukai.txt: 5.35813
    Isvedimas i faila kietiakai.txt: 7.99636
    Visas sugaistas laikas: 24.014 s
    
    studentai10000000.txt: dėl didelio failo dydžio kompiuteris nepajėgia atlikti veiksmų.


