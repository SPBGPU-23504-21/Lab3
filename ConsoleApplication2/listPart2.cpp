#include "listPart2.h"

template<typename T>T RandomElement(T r1, T r2){
	return r1 + rand() % (r2-r1+1);
}

list<int> create_list(int range1, int range2, int size){
	list<int> list;
	int i = 0;
	
	srand((int)time(0));
	while(i < size){
		list.push_back(RandomElement(range1, range2));
		i++;
	}
	return list;
}

void print_list(list<int> v){
   list<int>::iterator iter;
   
   cout << "[ ";
   iter = v.begin();
   while(iter!=v.end()){
	   cout << *iter <<", ";
	   ++iter;
   }
   cout << "] len: "<< v.size() << endl;
}

void special_print(list<int>v){
	list<int>::iterator iter = v.begin();
	list<int>::reverse_iterator r_iter = v.rbegin();
	int i = 0;
	cout <<"[ ";
	while(i != (v.size()/2)){
		cout << *iter << ", " << *r_iter << ", ";
		++iter;
		++r_iter;
		i++;
	}
	cout << "]";
}