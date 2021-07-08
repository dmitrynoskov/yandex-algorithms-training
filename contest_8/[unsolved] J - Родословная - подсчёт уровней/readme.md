# J. Родословная: подсчет уровней

В генеалогическом древе у каждого человека, кроме родоначальника, есть ровно один родитель. Каждом элементу дерева сопоставляется целое неотрицательное число, называемое высотой. У родоначальника высота равна 0, у любого другого элемента высота на 1 больше, чем у его родителя. Вам дано генеалогическое древо, определите высоту всех его элементов.

## Формат ввода
Программа получает на вход число элементов в генеалогическом древе *N*. Далее следует *N-1* строка, задающие родителя для каждого элемента древа, кроме родоначальника. Каждая строка имеет вид *имя_потомка* *имя_родителя*.

## Формат вывода
Программа должна вывести список всех элементов древа в лексикографическом порядке. После вывода имени каждого элемента необходимо вывести его высоту.

### Пример 1
Ввод | Вывод
---| ---
9 <br> Alexei Peter_I <br> Anna Peter_I <br> Elizabeth Peter_I <br> Peter_II Alexei <br> Peter_III Anna <br> Paul_I Peter_III <br> Alexander_I Paul_I <br> Nicholaus_I Paul_I | Alexander_I 4 <br> Alexei 1 <br> Anna 1 <br> Elizabeth 1 <br> Nicholaus_I 4 <br> Paul_I 3 <br> Peter_I 0 <br> Peter_II 2 <br> Peter_III 2

### Пример 2
Ввод | Вывод
---| ---
10 <br> AQHFYP MKFXCLZBT <br> AYKOTYQ QIUKGHWCDC <br> IWCGKHMFM WPLHJL <br> MJVAURUDN QIUKGHWCDC <br> MKFXCLZBT IWCGKHMFM <br> PUTRIPYHNQ UQNGAXNP <br> QIUKGHWCDC WPLHJL <br> UQNGAXNP WPLHJL <br> YURTPJNR QIUKGHWCDC | AQHFYP 3 <br> AYKOTYQ 2 <br> IWCGKHMFM 1 <br> MJVAURUDN 2 <br> MKFXCLZBT 2 <br> PUTRIPYHNQ 2 <br> QIUKGHWCDC 1 <br> UQNGAXNP 1 <br> WPLHJL 0 <br> YURTPJNR 2

### Пример 3
Ввод | Вывод
---| ---
10 <br> BFNRMLH CSZMPFXBZ <br> CSZMPFXBZ IHWBQDJ <br> FMVQTU FUXATQUGIG <br> FUXATQUGIG IRVAVMQKN <br> GNVIZ IQGIGUJZ <br> IHWBQDJ LACXYFQHSQ <br> IQGIGUJZ JMUPNYRQD <br> IRVAVMQKN GNVIZ <br> JMUPNYRQD BFNRMLH | BFNRMLH 3 <br> CSZMPFXBZ 2 <br> FMVQTU 9 <br> FUXATQUGIG 8 <br> GNVIZ 6 <br> IHWBQDJ 1 <br> IQGIGUJZ 5 <br> IRVAVMQKN 7 <br> JMUPNYRQD 4 <br> LACXYFQHSQ 0








## Примечания
Эта задача имеет решение сложности *O(n)*, но вам достаточно написать решение сложности *O(n<sup>2</sup>)* (не считая сложности обращения к элементам словаря). Пример ниже соответствует приведенному древу рода Романовых.
