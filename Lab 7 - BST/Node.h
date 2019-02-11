#ifndef Node_h
#define Node_h

#include "NodeInterface.h"

class Node : public NodeInterface {
    
public:
    
    int data;
    Node* left;
    Node* right;
    
    Node(int value, Node* leftChild = NULL, Node* rightChild = NULL) {
        data = value;
        left = leftChild;
        right = rightChild;
    }

    int getData() const {
        return data;
    }

    NodeInterface * getLeftChild() const {
        if (left == NULL) return NULL;
        else return left;
    }

    NodeInterface * getRightChild() const {
        if (right == NULL) return NULL;
        else return right;
    }
    
private:
    
    void setData(int newdata) {
        data = newdata;
    }
    
    void setLeftChild(Node* value) {
        left = value;
    }
    
    void setRightChild(Node* value) {
        right = value;
    }
};

#endif