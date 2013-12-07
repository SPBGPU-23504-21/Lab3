#include "QueueWithPriority.h"
#include "listPart2.h"
/*
1. ���� �������� ��������� ������ ������� � ������������, ������� ������������� ��������� �������. 
� ������� ����� ���� ��������� ��������, ������� �������� ��� ���������� ������������� ���� �� ���� ������� ���������� (low, normal, high)
�������� �� ������� ����������� � ������������ � �� ������������ (������� ����������� �������� � ����������� high, ����� normal, ����� low), �������� � ����������� ������������ ����������� �� ������� � ������� �� �����������. 
� ������� ����� ����� ����������� �������� ����������� � ��� �������� � ����������� low ����������� � ������ ����������� � ������� ����������� ���� ��������� �� high �
��������� �������� � ����������� normal.
���� �������� ��������� ����� ������:
typedef enum 
{
    LOW, 
    NORMAL,
    HIGH 
} ElementPriority;
typedef struct
{
    string name;
} QueueElement;
class QueueWithPriority
{
    // �����������, ������� ������ �������
   QueueWithPriority();

    // ����������
   ~QueueWithPriority();

    // �������� � ������� ������� element � ����������� priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // �������� ������� �� �������
    // ����� ������ ���������� ������� � ���������� �����������, ������� ���
    // �������� � ������� ������ ������
    QueueElement GetElementFromQueue();

    // ��������� �����������
    void Accelerate();
};
����������� ���� �����, ��������� list ��� deque. ��������� ���� �����.
������������� ���������, �������� ���������� �����, ������������, ���  ����� �������� ���������.
2.	������������ ���������, �������
a.	��������� list<int> 15 ���������� ���������� �� 1 �� 20, ������ ����� ��������� �� 0 �� 20 �������� (����������� ��������� �� ����� ������ 0, 1. 2, 3, 4, 5, 7, 14)
b.	������� ���������� ������ � ��������� �������: ������ �������, ��������� �������, ������ �������, ������������� �������, ������ ������� � �.�.

�������� ���� ������ ��������:
1 2 3 4 5 6 7 8
�� ����� ����� ����� ��� 
1 8 2 7 3 6 4 5

���������: ����� ������������ �������� � ��������������� ���������

*/

void main(void){
	string name = "PRIVET LALKA";
	char *name1 = {"poriesto"};
	QueueElement q1(name, HIGH);
	QueueElement q2(name1, LOW);
	QueueElement q3(name1, LOW);
	QueueElement q4(name1, LOW);
	QueueWithPriority qu1;
	list<int>ListOfInt;
	int range1 = 1, range2 = 20, size = 8;

	cout << "=========================Part1==================================================" << endl;
	cout << "QueueElement1 = " << q1 << endl;
	cout << "QueueElement2 = " << q2 << endl;
	qu1.put(q1);
	qu1.put(q2);
	qu1.put("Mayana", NORMAL);
	qu1.put(q3);
	qu1.put(q4);
	cout << "Queue:" << endl;
	qu1.print();
	cout << "List size = " <<qu1.size() << endl;
	cout << "=====Accelerate QueueWithPriority============================" << endl;
	qu1.accelerate();
	qu1.print();
	
	cout << endl << "=========================Part2==================================================" << endl;
	ListOfInt = create_list(range1, range2, size);
	print_list(ListOfInt);
	special_print(ListOfInt);
}