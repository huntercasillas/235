#pragma once
#include "AVLInterface.h"
#include "Node.h"

class AVL: public AVLInterface {
public:

	AVL();
	~AVL();

	virtual NodeInterface * getRootNode() const;
	virtual Node* recAdd(Node* curr, int value);
	virtual bool contains(int value);
	virtual bool recContains(Node* curr, int value);
	virtual bool add(int data);

	Node* IOP(Node* curr, Node* rNode);
	Node* recRemove(Node* curr, int x);

	void RotateRight(Node* a, Node* b);
	void RotateLeft(Node* a, Node* b, Node* c);
	void LeftLeft(Node* a, Node* b);
	void LeftRight(Node* a, Node* b, Node* c);

	virtual bool remove(int data);
	virtual void clear();

	virtual int size();
	virtual Node* balance(Node* node);
};
