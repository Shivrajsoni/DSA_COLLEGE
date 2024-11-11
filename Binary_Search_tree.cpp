#include<iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    Node(int val){
        left = right =NULL;
        data = val;
    }
};

Node *insert(Node *root,int val){
    if (root==NULL)
    {
        return new Node(val);
    }
    if(root->data<val){
        root->right = insert(root->right,val);
    }
    else if(root->data>val){
        root->left = insert(root->left,val);
    }
    return root;

}

// inorder Traversal
void inorder(Node *root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}



int main(){
    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
}