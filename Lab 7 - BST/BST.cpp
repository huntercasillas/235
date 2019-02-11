#include <stdio.h>
#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() {
    rootNode = NULL;
}

BST::~BST() {
    clear();
}

NodeInterface * BST::getRootNode() const {
    return rootNode;
}

bool BST::recContains(Node* current, int value) { 
    bool contains = false;

    if (current == NULL) { 
        return false;
    } else if (value == current->data) {
        contains = true;
    } else if (value < current->data) {
        contains = recContains(current->left, value);
    } else if (value > current->data) {
        contains = recContains(current->right, value);
    } else {
        contains = false;
    }
    return contains;
}

bool BST::contains(int value) {
    if (rootNode == NULL) {
        return false;
    } else {
        bool contains = recContains(rootNode, value);
        return contains;
    }
}

Node* BST::recAdd(Node* current, int value) {
    if (current == NULL) {
        return new Node(value);
    } else if (value < current->data) {
        current->left = recAdd(current->left, value);
        return current;
    } else if (value > current->data) {
        current->right = recAdd(current->right, value);
        return current;
    }
    return current;
}

bool BST::add(int value) {
    if (!contains(value)) {
        rootNode = recAdd(rootNode, value);
        return true;
    } else {
        return false;
    }
}

Node* BST::IOP(Node* current, Node* parent) {
    if (current->right == NULL) {
        int swapData = parent->data;
        parent->data = current->data;
        current->data = swapData;

        Node* savedNode = current->left;

        delete current;
        return savedNode;
    } else {
        current->right = IOP(current->right, parent);
        return current;
    }
}

Node* BST::recRemove(Node* current, int value) {
    if (value == current->data) {
        if (current->right == NULL && current->left != NULL) {
            Node* temp = current->left;
            delete current;
            return temp;
        } else if (current->left == NULL ) {
            Node* temp = current->right;
            delete current;
            return temp;
        } else {
            current->left = IOP(current->left, current);
            return current;
        }
    }

    if (value < current->data) {
        current->left = recRemove(current->left, value);
        return current;
    }

    if (value > current->data) {
        current->right = recRemove(current->right, value);
        return current;
    }
    return current;
}

bool BST::remove(int data) {
    if(rootNode == NULL) {
        return false;
    } else if (contains(data)) {
        rootNode = recRemove(rootNode, data);
        return true;
    } else {
        return false;
    }
}

void BST::clear() {
    while (rootNode != NULL) {
        remove(rootNode->data);
    }
    rootNode = NULL;
}
