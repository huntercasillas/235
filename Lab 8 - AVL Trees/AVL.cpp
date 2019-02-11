#include "AVL.h"
#include <iostream>

using namespace std;

int size_of_tree = 0;

Node* rootNode = NULL;

AVL::AVL() {
	rootNode = NULL;
}
AVL::~AVL() {
	clear();
}

	NodeInterface * AVL::getRootNode() const {
		return rootNode;
	}

	int AVL::size() {
		return size_of_tree;
	}

	bool AVL::recContains(Node* current, int value) {
    bool contains = false;

    	if (current == NULL) {
        	return false;
    	} 
    	else if (value == current->data) {
        	contains = true;
    	} 
    	else if (value < current->data) {
        	contains = recContains(current->left, value);
    	} 
    	else if (value > current->data) {
        	contains = recContains(current->right, value);
    	} 
    	else {
        	contains = false;
    	}
    	
    	return contains;
}

	bool AVL::contains(int value) {
		if (rootNode == NULL) {
			return false;
		} 
		else {
			bool contains = recContains(rootNode, value);
			return contains;
		}
	}

	Node* AVL::recAdd(Node* current, int value) {
    	if (current == NULL) {
        	return new Node(value);
    	} 
    	else if (value < current->data) {
        	current->left = recAdd(current->left, value);
        	return balance(current);
    	} 
    	else if (value > current->data) {
        	current->right = recAdd(current->right, value);
        	return balance(current);
    	}
    	return current;
	}

	void AVL::RotateRight(Node* a, Node* b) {
		a->right = b->left;
		b->left = a;
		
		a->updateHeight();
		b->updateHeight();
	}

	void AVL::RotateLeft(Node* a, Node* b, Node* c) {
		a->right = c;
		b->left = c->right;
		c->right = b;

		RotateRight(a, c);

		a->updateHeight();
		b->updateHeight();
		c->updateHeight();
	}

	void AVL::LeftLeft(Node* a, Node* b) {
		a->left = b->right;
		b->right = a;

		a->updateHeight();
		b->updateHeight();
	}

	void AVL::LeftRight(Node* a, Node* b, Node* c) {
		a->left = c;
		b->right = c->left;
		c->left = b;

		LeftLeft(a, c);

		a->updateHeight();
		b->updateHeight();
		c->updateHeight();
	}

	Node* AVL::balance(Node* a) {
		if (a == NULL) {
			return NULL;
		}
		a->updateHeight();

		if (a->getBalance() > 1) {
			Node* b = a->right;

			if (b->getBalance() < 0) {
				Node* c = b->left;
				RotateLeft(a, b, c);
				return c;
			} 
			else {
				RotateRight(a, b);
				return b;
			}
		} 
		else if (a->getBalance() < -1) {
			Node* b = a->left;

			if (b->getBalance() > 0) {
			 	Node* c = b->right;
				LeftRight(a, b, c);
				return c;
			 } 
			 else {
				LeftLeft(a, b);
				return b;
			}
		} 
		else {
			return a;
		}
	}

	bool AVL::add(int value) {
		if (!contains(value)) {
				rootNode = recAdd(rootNode, value);
				return true;
		} 
		else {
				return false;
		}
	}

	Node* AVL::IOP(Node* current, Node* parent) {
		if (current->right == NULL) {
        int swapData = parent->data;
        parent->data = current->data;
        current->data = swapData;

        Node* savedNode = current->left;

        delete current;

        return balance(savedNode);
    } 
    else {
        current->right = IOP(current->right, parent);
        return balance(current);
    	}
	}

	Node* AVL::recRemove(Node* current, int value) {
		if (value == current->data) {

        if (current->right == NULL && current->left != NULL) {
            Node* temp = current->left;
            delete current;
            return balance(temp);
        } 
        else if (current->left == NULL ) {
            Node* temp = current->right;
            delete current;
            return balance(temp);
        } 
        else {
            current->left = IOP(current->left, current);
            return balance(current);
        }
    }

    if (value < current->data) {
        current->left = recRemove(current->left, value);
        return balance(current);
    	}

    if (value > current->data) {
        current->right = recRemove(current->right, value);
        return balance(current);
    	}
    return balance(current);
	}

	bool AVL::remove(int data) {
		if(rootNode == NULL) {
			return false;
		} else if (contains(data)) {
				rootNode = recRemove(rootNode, data);
				return true;
		} else {
				return false;
		}
	}

	void AVL::clear() {
		while (rootNode != NULL) {
        remove(rootNode->data);
    }
    	rootNode = NULL;
	}