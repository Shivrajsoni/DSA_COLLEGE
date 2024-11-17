#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left, right;
    int height;
    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// get Height Function
int getHeight(Node *root){
    if(root == nullptr){
        return 0;
    }
    else{
        return root->height;
    }
}
// Balancing Function
int getBalance(Node *root){
    if(root == nullptr){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

// left Rotation
Node *leftRotation(Node *root){
    Node *Child = root->right;
    Node *Childleft = child->left;
    child->left = root;
    root->right = Childleft;

    // update the Height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

// Right Rotation
Node *rightRotation(Node *root){
    Node *child = root->left;
    Node *ChildRight = child->right;
    child->right = root;
    root->left = ChildRight;
    
    // update The Height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}


Node *insert(Node *root,int key){
    if(!root){
        return new Node(key);
    }
    else{
        if(key<root->data){
            root->left=insert(root->left,key);
        }
        else if(key>root->data){
            root->right=insert(root->right,key);
        }
        else{
            return root;
        }
    }

    // Update Height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    
    int balance=getBalance(root);

    //Left left Wala Case
    if(balance >1 && key <root->left->data){
        return rightRotate(root);
    }
    // Right Right Wala Case
    else if(balance <-1 && key>root->right->data){
        return leftRotate(root);
    }
    else if(balance >1 && key > root->left->data){
        root->left=leftRotate(root->left);
        return rightRotation(root);
    }
    else if(balance <-1 && key< root->right->data){
        root->right=rightRotate(root->right);
        return leftRotation(root);
    }
    else{
        return root;
    }
}

int main()
{
    AVLTree<int> avl;

    // Insert nodes into the AVL tree
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    // Print the inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree: ";
    avl.printInorder();

    // Remove a node from the AVL tree
    avl.remove(30);
    cout << "Inorder traversal after removing 30: ";
    avl.printInorder();

    // Search for nodes in the AVL tree
    cout << "Is 25 in the tree? "
         << (avl.search(25) ? "Yes" : "No") << endl;
    cout << "Is 30 in the tree? "
         << (avl.search(30) ? "Yes" : "No") << endl;

    return 0;
}
