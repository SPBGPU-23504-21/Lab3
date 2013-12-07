#include "QueueWithPriority.h"

QueueElement::QueueElement(string _name, ElementPriority _priority){
    name=_name;
    priority=_priority;
}

QueueElement::QueueElement(char _name[], ElementPriority _priority){
    name = string(_name),
    priority = _priority;
}

ostream& operator<<( ostream &ostr, const QueueElement &L ){
    char *priority_name;
    switch (L.priority){
    case LOW: priority_name = "LOW";
        break;
    case NORMAL: priority_name = "NORMAL";
        break;
    case HIGH: priority_name = "HIGH";
        break;
    default: priority_name = "None";
    }

    ostr << "Q("<< L.name << ", " << priority_name << ")";
    return ostr;
}

bool operator<(const QueueElement &leftel, const QueueElement &rightel){
	return(leftel.priority < rightel.priority);
}

//class QueueWithPriority
//constructor
QueueWithPriority::QueueWithPriority()
{

}
/// Destructor
QueueWithPriority::~QueueWithPriority()
{

}

void QueueWithPriority::put(const QueueElement &element){
	queue_iterator_type iter;
    int check;
    bool insert = false;
    if ((!queue.empty()) & (element.priority != LOW)){
		iter = queue.begin();
		while(iter != queue.end()){
			check = iter->priority - element.priority;
			if(check == -1){
				queue.insert(iter, element);
				insert = true;
				break;
			}
			iter++;
		}
    } 
	else {
        queue.push_back(element);
    }
}

void QueueWithPriority::put(const char *name, ElementPriority priority){
	put(QueueElement(name, priority));
}

QueueElement QueueWithPriority::get(){
	if(!queue.empty()){
		QueueElement qe = queue.front();
		queue.pop_front();
		return qe;
	}
	else{
		cerr << "No more elements in queue" << endl;
		throw "fail";
	}
}

void QueueWithPriority::accelerate(){
	queue_iterator_type iter, first_drop;
	bool drop = false;
	if(!queue.empty()){
		iter=--queue.end();
		while(iter!=queue.begin()){
			if(iter->priority == LOW){
				iter->priority = HIGH;
				first_drop = iter;
				drop = true;
			}
			iter--;
		}
		if(drop){
			iter = queue.begin();
			while(iter != queue.end()){
				if(iter->priority == NORMAL){
					queue.splice(iter, queue, first_drop, queue.end());
				}
				iter++;
			}
		}	
	}
}

void QueueWithPriority::print(){
	queue_iterator_type iter;
    cout << "[";
    for(iter=queue.begin(); iter != queue.end();iter++){
        cout<< *iter<< ",";
    }
    cout << "]" << endl;
}

int QueueWithPriority::size(){
	return queue.size();
}