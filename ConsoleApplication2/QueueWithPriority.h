#include <iostream>
#include <list>
#include <deque>
#include <string>
using namespace std;
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
������������� ���������, �������� ���������� �����, ������������, ���  ����� �������� ���������.*/

typedef enum{
	LOW,
	NORMAL,
	HIGH
} ElementPriority;

struct QueueElement{
	string name;
	ElementPriority priority;
	QueueElement(string name, ElementPriority priority);
	QueueElement(char name[], ElementPriority priority);
	friend ostream& operator<<(ostream &ostr, const QueueElement &L);
	friend bool operator<(const QueueElement &leftel, const QueueElement &rightel);
};

typedef list<QueueElement> queue_type;
/// Container iterator type for #QueueWithPriority
typedef queue_type::iterator queue_iterator_type;
/// Container reverse iterator type for #QueueWithPriority
typedef queue_type::reverse_iterator queue_reverse_iterator_type;

class QueueWithPriority{
private:
    queue_type queue;
public:
	QueueWithPriority();
	~QueueWithPriority();
	void put(const QueueElement &element);
	void put(const char *name, ElementPriority priority);
	QueueElement get(void);
	void accelerate(void);
	int size(void);
	void print();
};