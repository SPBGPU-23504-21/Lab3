/*
2.	–азработайте программу, котора€
a.	«аполн€ет list<int> 15 случайными значени€ми от 1 до 20, список может содержать от 0 до 20 значений (об€зательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
b.	¬ыводит содержимое списка в следующем пор€дке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.

Ќапример если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид 
1 8 2 7 3 6 4 5

ѕодсказка: можно использовать рекурсию и двунаправленные итераторы

*/
#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <time.h>
using namespace std;

template<typename T>T RandomElement(T r1, T r2);
list<int> create_list(int range1, int range2, int size);
void print_list(list<int> v);
void special_print(list<int>v);