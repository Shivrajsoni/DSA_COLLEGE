#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    int height ;
    Node (int val){
        data = val;
        left = right = nullptr;
        height = 1;
    }
}

Node* AlmostInsertionBinaryTree(Node *root,int val){
    Node *newNode = new Node(val);
    if(root==nullptr){
        return newNode;
    }
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        // left Node inserting
        if(temp->left == nullptr){
            temp->left=newNode;
            return root;
        }
        else{
            q.push(temp->left);
        }

        // Right Node inserting
        if(temp->right == nullptr){
            temp->right=newNode;
            return root;
        }
        else{
            q.push(temp->right);
        }
    }
    return root;

}


// printing it by'level order traverasal
void printLevelOrder(Node *root){
    if(root==nullptr){
        return;
    }
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left!=nullptr){
            q.push(temp->left);
        }
        else if(temp->right!=nullptr){
            q.push(temp->right);
        }
    }
}

int getHeight(Node *root){
    if(root==nullptr){
        return 0;
    }
    return root->height;

}

int getbalance(Node *root){
    if(root==nullptr){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
// Avalenche tree
// left and right Rotation

// Node* leftRotate(Node* root){
//     Node* temp = root->right;
//     Node *remp = 
//     while(temp)
// };

// Node *rightRotate(Node *root){
//     Node *temp = root->left;

// }

int main(){
    Node* root = nullptr;
    AlmostInsertionBinaryTree(root,3);
    AlmostInsertionBinaryTree(root,5);
    AlmostInsertionBinaryTree(root,4);
    AlmostInsertionBinaryTree(root,7);
    AlmostInsertionBinaryTree(root,6);

    cout<<"Level Order traversal of Binary tree will be"<< endl;
    printLevelOrder(root);
}