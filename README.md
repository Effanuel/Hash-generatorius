
Hash generatorius Blockchain kursui

# Hash-generatorius
Hash generatorius Blockchain kursui
## Reikalavimai
1. Maišos funkcijos įėjimas (angl. *input*) gali būti <u>bet kokio dydžio</u> simbolių eilutė (angl. *string*).
2. Maišos funkcijos išėjimas (angl. *output*) visuomet yra <u>to paties fiksuoto dydžio</u> rezultatas.
3. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input reikšmėi yra apskaičiuojamas nesunkiai - efektyviai.
4. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (angl. *input*'ui) išvedimas (angl. *output*'as) <u>visuomet</u> yra tas pats.
5. Iš funkcijos rezultato (*output*'o) praktiškai neįmanoma atgaminti įvedimo (*input*'o).
6. Praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų (*input*'ų), kad jiems gautume tą patį *hash*'ą, t. y.,: *m1 != m2*, bet *h(m1) = h(m2)*.
7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės.

---

## Funkcijos

* String hash'inimas per `Command Line Argument`'ą:
  * `make run sqertqerwqerqvwe` (be `.txt`)
* Failo hash'inimas per `Command Line Argument`'ą:
  * `make run same_1.txt`
  
  arba
   * `make run same_1.txt same_2.txt` *(jei norit palyginti hash'us)*
  
  Galimi failai:
  * **diff_1.txt ir diff_2.txt** - visiškai skirtingi simboliai;
  * **empty.txt** - tuščias failas;
  * **same_1.txt ir same_2.txt** - iš daug simbolių, bet skiriasi tik vienas;
  * **single_1.txt ir single_2.txt** - iš vieno bet skirtingo simbolio;

* Efektyvumo patikrinimas per `Command Line Argument`'ą:
  * `make run konstitucija.txt`
  
* Funkcionalumas per consolę:
  * `make run`
  
  ![console](https://github.com/Effanuel/Hash-generatorius/blob/master/console.png)


---
## Prerequisites
1. GNU C++ Compiler

## Installation
1. [Atsisiūskite naujausią versiją.]()
2. Extract failus.
3. Per command-line:
```
cd HashGenerator
make run
```
4. Executable yra **./HashGenerator/bin/project.exe**
```
cd bin
./project
```
---

## Tyrimo analizė
### Reikalavimai
- 1-3 - 
- 4 - Efektyvumo paskaičiavimas: `make run konstitucija.txt`
- 7 - Vidurkinės, minimalios ir maksimalios bitų "skirtingumo" reikšmės 1,000,000 porų:







