#pragma once
#include <iostream>
#include <sstream>
#include "LinkedListInterface.h"
using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T> {
	struct Node {
		T data;
		Node *next;

		Node(T value) {
			data = value;
			next = NULL;
		}
		~Node() {}
	};

protected:
	int listSize = 0;
	Node *begin;
	Node *current;
	Node *finish;

public:
	LinkedList() {
		begin = NULL;
		current = NULL;
		finish = NULL;
	}

	~LinkedList() {
			clear();
	}

	bool find(T value) {
			if (begin != NULL) {
				current = begin;
				while (current != NULL)
					if(current->data == value) {
						return true;
					} else {
					current = current->next;
					}
				if (current == NULL) {
					return false;
				}
			} else {
				return false;
			}
	}

	void insertHead(T value) {
		if(listSize == 0) {
			Node* insert = new Node(value);
			begin = insert;
			finish = insert;
			listSize++;
		} else {
			bool isDuplicate = find(value);
			if(isDuplicate == false) {
				Node* insert = new Node(value);
				insert->next = begin;
				begin = insert;
				listSize++;
			}
		}
	}

	void insertTail(T value) {
			if (!this->find(value)) {
					if (begin == NULL) {
						begin = new Node(value);
						listSize++;
						finish = begin;
					}
					else {
						finish->next = new Node(value);
						listSize++;
						finish = finish->next;
					}
				}

	}

	void insertAfter(T value, T insertionNode) {
		if (begin != NULL) {
		bool isDuplicate = find(value);
		bool insertionExist = find(insertionNode);

			if (isDuplicate == false && insertionExist == true) {
				current = begin;
				Node* insert = NULL;
				while(current != NULL) {
					if (current->data == insertionNode) {
						insert = new Node(value);
						insert->next = current->next;
						current->next = insert;
						if (insert->next == NULL) {
							finish = insert;
						}
						current = insert;
					}
					current = current->next;
				}
			}
		}
	}

void remove(T value) {
	if (begin != NULL) {
		current = begin;
		Node* previous = NULL;

		while(current != NULL) {
			if (current->data == value) {
				if (previous == NULL) {
					begin = current->next;
					delete current;
				} else {
					previous->next = current->next;
					if (previous->next == NULL) {
						finish = previous;
					}
					delete current;
				}
				break;
			}
			previous = current;
			current = current->next;
		}
	}
}

	void clear() {
		if (begin != NULL) {
					current = begin;
					Node* position = NULL;
					while(current != NULL) {
						position = current->next;
						delete current;
						current = position;
					}
				}
				begin = NULL;
				current = NULL;
				finish = NULL;
	}

	T at(int index) {
		if (index >= size() || index < 0) {
			throw std::out_of_range("Out of Range");
		} else {
			Node *curr = begin;
			for (int i = 0; i < index; i++)
			{
				curr = curr->next;
			}
			return curr->data;
		}
	}

	int size() {
		int position = 0;
		Node *current = begin;

		while (current != NULL) {
			current = current->next;
			position++;
		}
		return position;
	}

	string printList() {
		Node* print = begin;
		stringstream ss;
		while (print != NULL) {
			ss << print->data << " ";
			print = print->next;
		}
		return ss.str().substr(0, ss.str().length() - 1);
	}
};
