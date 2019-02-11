#pragma once
#include "NodeInterface.h"
#include <iostream>

class Node : public NodeInterface {

public:

	int data;
	Node* left;
	Node* right;
	int height;

	Node(int value, Node* leftChild = NULL, Node* rightChild = NULL, int tall = 0) {
		data = value;
		left = leftChild;
		right = rightChild;
		height = tall;

	}

	int getData() const{
		return data;
	}

	NodeInterface * getLeftChild() const{
		return left;
	}

	NodeInterface * getRightChild() const{
		return right;
	}

	int getHeight(){
		cout <<"\ngetHeight(" << this->data <<")..." << endl;
		cout << "height: " << height << endl;
		return height;
	}

	void setHeight(int value){
		this->height = value;
	}

	void updateHeight() {
		int leftHeight;
		if (left == NULL)leftHeight = -1;
		else leftHeight = left->height;

		int rightHeight;
		if (right == NULL) rightHeight = -1;
		else rightHeight = right->height;

		height = max(leftHeight, rightHeight) + 1;
	}

	int getBalance() {
		int leftHeight = (left == NULL) ? -1 : left->height;
		int rightHeight = (right == NULL) ? -1 : right->height;
		return rightHeight - leftHeight;
	}

};
