#include <iostream>
#include <list>
#include <deque>
#include <string>
using namespace std;
/*
1. Ниже приведен интерфейс класса очереди с приоритетами, который функционирует следующим образом. 
В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета (low, normal, high)
Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, потом normal, потом low), элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления. 
В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают свой приоритет до high и
«обгоняют» элементы с приоритетом normal.
Ниже приведен интерфейс этого класса:
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
    // Конструктор, создает пустую очередь
   QueueWithPriority();

    // Деструктор
   ~QueueWithPriority();

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue();

    // Выполнить акселерацию
    void Accelerate();
};
Реализовать этот класс, используя list или deque. Объяснить свой выбор.
Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.*/

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