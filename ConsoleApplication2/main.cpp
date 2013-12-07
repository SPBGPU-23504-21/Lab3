#include "QueueWithPriority.h"
#include "listPart2.h"
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
Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.
2.	Разработайте программу, которая
a.	Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
b.	Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.

Например если список содержит:
1 2 3 4 5 6 7 8
то вывод будет иметь вид 
1 8 2 7 3 6 4 5

Подсказка: можно использовать рекурсию и двунаправленные итераторы

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