

#include <iostream>
#include <vector>
using namespace std;

// B-Tree Node Structure
class BTreeNode {
public:
    vector<int> keys;      // Keys in the node
    vector<BTreeNode*> children; // Child pointers
    bool isLeaf;           // True if the node is a leaf
    int t;                 // Minimum degree (order)

    BTreeNode(int t, bool isLeaf);
    void insertNonFull(int key);
    void splitChild(int i, BTreeNode* y);
    void traverse();

    BTreeNode* search(int key);
};

// Constructor
BTreeNode::BTreeNode(int t, bool isLeaf) {
    this->t = t;
    this->isLeaf = isLeaf;
}

// Traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (!isLeaf)
            children[i]->traverse();
        cout << keys[i] << " ";
    }

    if (!isLeaf)
        children[i]->traverse();
}

// Search for a key in a subtree rooted with this node
BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < keys.size() && key > keys[i])
        i++;

    if (i < keys.size() && keys[i] == key)
        return this;

    if (isLeaf)
        return nullptr;

    return children[i]->search(key);
}

// Insert when node is not full
void BTreeNode::insertNonFull(int key) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.insert(keys.end(), key);
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
    } else {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->keys.size() == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key)
                i++;
        }
        children[i + 1]->insertNonFull(key);
    }
}

// Split child node
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->isLeaf);
    z->keys.resize(t - 1);

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        z->children.resize(t);
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->keys.resize(t - 1);
    children.insert(children.begin() + i + 1, z);
    keys.insert(keys.begin() + i, y->keys[t - 1]);
}

// B-Tree Structure
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t) {
        root = nullptr;
        this->t = t;
    }

    void traverse() {
        if (root)
            root->traverse();
    }

    BTreeNode* search(int key) {
        return root == nullptr ? nullptr : root->search(key);
    }

    void insert(int key);
};

// Insert a key into the B-Tree
void BTree::insert(int key) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys.push_back(key);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);

            int i = (s->keys[0] < key) ? 1 : 0;
            s->children[i]->insertNonFull(key);

            root = s;
        } else {
            root->insertNonFull(key);
        }
    }
}

// Example Usage
int main() {
    BTree bTree(3);

    bTree.insert(10);
    bTree.insert(20);
    bTree.insert(5);
    bTree.insert(6);
    bTree.insert(12);
    bTree.insert(30);
    bTree.insert(7);
    bTree.insert(17);

    cout << "Traversal of B-Tree: ";
    bTree.traverse();
    cout << endl;

    int key = 6;
    (bTree.search(key) != nullptr) ? cout << key << " is found\n" : cout << key << " is not found\n";

    return 0;
}
