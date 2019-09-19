
Hash generatorius Blockchain kursui

# Hash-generatorius
Hash generatorius Blockchain kursui
1. Maišos funkcijos įėjimas (angl. *input*) gali būti <u>bet kokio dydžio</u> simbolių eilutė (angl. *string*).
2. Maišos funkcijos išėjimas (angl. *output*) visuomet yra <u>to paties fiksuoto dydžio</u> rezultatas.
3. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input reikšmėi yra apskaičiuojamas nesunkiai - efektyviai.
4. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (angl. *input*'ui) išvedimas (angl. *output*'as) <u>visuomet</u> yra tas pats.
5. Iš funkcijos rezultato (*output*'o) praktiškai neįmanoma atgaminti įvedimo (*input*'o).
6. Praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų (*input*'ų), kad jiems gautume tą patį *hash*'ą, t. y.,: *m1 != m2*, bet *h(m1) = h(m2)*.
7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės.

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
