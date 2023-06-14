#include"LInkList.h"
#include "Node.h"

LinkList::LinkList() : _head(nullptr), _tail(nullptr), _size(0) {};

void LinkList::AddTail(int data) {
	Node* newTail = new Node(data);
	_size++;
	if (_head == nullptr) {
		_head = newTail;
		_tail = newTail;
		return;
	}
	_tail->prev = newTail;
	newTail->next = _tail;
	_head->next = newTail;
	_tail = newTail;
	_tail->prev = _head;
}

void LinkList::AddHead(int data) {
	Node* newHead = new Node(data);
	if (_head == nullptr) {
		_size++;
		_tail = newHead;
		_head = newHead;
		return;
	}
	_head->next = newHead;
	newHead->prev = _head;
	newHead->next = _tail;
	_head = newHead;
}

void LinkList::ShowList() {
	if (_size == 0) {
		std::cout << "No elements";
		return;
	}
	int index = 0;
	for (Node* nodePtr = _head; index != _size; nodePtr = nodePtr->prev, index ++) 
		std::cout << "Data: " << nodePtr->GetData() << '\n';
}

void LinkList::DeleteElement(int index) {
	/*Node* deleted = FindElement(index);
	if (deleted == _head) {
		_head->prev->next = _head->next;
	}
	if (_size < 3) {
		Node* deleted = FindElement(index);
		deleted->next->next = nullptr;
		deleted->next->prev = nullptr;
		_size--;
		return;

	}*/
	_size--;
	if (index == 1 && _size == 1) {
		
		delete(_head);
		return;
	}
	Node* deleted = FindElement(index);
	Node* prevDeleted = deleted->prev;
	Node* nextDeleted = deleted->next;
	prevDeleted->next = nextDeleted;
	nextDeleted->prev = prevDeleted;
	if (deleted == _head)
		_head = deleted->prev;
	else
		if (deleted == _tail)
			_tail = deleted->next;
	
	delete(deleted);
}

Node* LinkList::FindElement(int index) {
	if (index <= 0 || index > _size) return nullptr;
	if (index == 1) return _head;
	else if (index == _size) return _tail;
	Node* nodePtr = _head;
	index--;
	while (index != 0) {
		nodePtr = nodePtr->prev;
		index--;
	}
	return nodePtr;
}


void LinkList::DeleteList() {
	Node* nodePtr = _tail;
	while (_size > 0) {
		nodePtr = nodePtr->next;
		delete(_tail);
		_tail = nodePtr;
		_size--;
	}
		
}