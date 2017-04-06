#include <iostream>
#include "BBTree.h"

bool BBTree::Node::search(const int key) const {
    bool result;
    if(this->key < key) {
        result = this->right->search(key);
    } else {
        result = this->left->search(key);
    }
    return result;
}

BBTree::Node *BBTree::Node::insert(const int key, const double alpha) {
    Node *insertedNode = nullptr;

    if(this->key < key) {
        if(this->right == nullptr) {
            this->right = new Node(key);
            insertedNode = this->right;
        } else {
            this->right->insert(key, alpha);
        }
    }

    if(this-> key > key) {
        if(this->left == nullptr) {
            this->left = new Node(key);
            insertedNode = this->left;
        } else {
            this->left->insert(key, alpha);
        }
    }

    return insertedNode;
}

BBTree::Node *BBTree::Node::remove(const int key, const double alpha) {
    return nullptr;
}

int BBTree::Node::getWeight() {
    int totalWeight = this->weight;
    if(this->left == nullptr && this->right != nullptr) {
        totalWeight = this->right->getWeight() + 1;
    }
    if(this->left != nullptr && this->right == nullptr) {
        totalWeight = this->left->getWeight() + 1;
    }
    if(this->left != nullptr && this->right != nullptr) {
        totalWeight = this->right->getWeight() + this->left->getWeight();
    }
    return totalWeight;
}

bool BBTree::search(const int key) const {
    if(root != nullptr) {
        return root->search(key);
    }
    return false;
}

void BBTree::insert(const int key) {
    if (root != nullptr) {
        if (!root->search(key)) {
            root->insert(key, alpha);
        }
    }
    root = new Node(key);
}

void BBTree::remove(const int key) {
    if (root != nullptr) {
        if (root->search(key)) {
            root->remove(key, alpha);
        }
    }
}
