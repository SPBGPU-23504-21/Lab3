/*
2.	������������ ���������, �������
a.	��������� list<int> 15 ���������� ���������� �� 1 �� 20, ������ ����� ��������� �� 0 �� 20 �������� (����������� ��������� �� ����� ������ 0, 1. 2, 3, 4, 5, 7, 14)
b.	������� ���������� ������ � ��������� �������: ������ �������, ��������� �������, ������ �������, ������������� �������, ������ ������� � �.�.

�������� ���� ������ ��������:
1 2 3 4 5 6 7 8
�� ����� ����� ����� ��� 
1 8 2 7 3 6 4 5

���������: ����� ������������ �������� � ��������������� ���������

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