#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "LInkList.h"

//Кольцовой двухсвязный список
int main()
{
	LinkList list;
	list.AddHead(10);
	list.AddTail(111);
	list.AddTail(22);
	list.AddTail(33);
	list.AddTail(44);
	list.AddTail(55);
	list.AddTail(66);
	list.ShowList();
	std::cout << "\n\n";
	std::cout << list.FindElement(2)->GetData();
	std::cout << "\n\n";
	list.DeleteList();
	list.ShowList();

	return 0;
}

