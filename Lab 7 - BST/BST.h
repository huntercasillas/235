#ifndef BST_h
#define BST_h

#include "BSTInterface.h"
#include "Node.h"

class BST: public BSTInterface {
    
private:
    Node* rootNode;
    int size_of_tree = 0;
    
public:
    BST();
    ~BST();
    
    virtual NodeInterface * getRootNode() const;
    virtual Node* recAdd(Node* curr, int value);
    virtual bool contains(int value);
    virtual bool recContains(Node* curr, int value);
    virtual bool add(int data);
    
    Node* IOP(Node* curr, Node* rNode);
    Node* recRemove(Node* curr, int x);
    
    virtual bool remove(int data);
    virtual void clear();
};

#endif