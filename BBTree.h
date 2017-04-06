#ifndef BBTREE_BBTREE_H_H
#define BBTREE_BBTREE_H_H

class BBTree {

private:

    struct Node {
        const int key;
        Node *left = nullptr;
        Node *right = nullptr;
        int weight = 2; // Anzahl Blätter
        Node(const int k) : key(k) {}
        Node(const int k, Node *l, Node *r) : key(k), left(l), right(r) {}
        bool search(const int key) const;
        Node *insert(const int key, const double alpha);
        Node *remove(const int key, const double alpha);
        int getWeight();
    };

    const double alpha;
    Node *root;

public:

    BBTree(const double a) : alpha(a) {}

    bool search(const int key) const;
    void insert(const int key);
    void remove(const int key);

};

#endif //BBTREE_BBTREE_H_H
