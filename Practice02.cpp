
// tree creation with the help of pre and in order traversal
#include<iostream>
using namespace std;
struct TreeNode {
	int data;
	TreeNode* Left;
	TreeNode* right;
	TreeNode(int x){
		data = x;
		left = right = nullptr;
	}
}
TreeNode* buildTreeHelper(vector<int>&preorder, vector<int>&inorder,int inStart,int inEnd, int &PreIndex,unordered_map<int,int>&inMap){
	if(inStart>inEnd)
		return NULL;

	int rootValue = preorder[PreIndex++];

	TreeNode *root = new TreeNode(rootValue);

	int inRoot = inMap[rootValue];

	root->left = buildTreeHelper(preorder,inorder,inStart,inRoot-1,PreIndex,inMap);
	root->right = buildTreeHelper(preorder,inorder,inRoot+1,inEnd,PreIndex,inMap);
	return root;
}

TreeNode* BuildMain(vector<int>&preorder,vector<int>&inorder){
	int preIndex =0;
	unordered_map<int,int>inMap;
	for(int i=0;i<inorder.size();i++){
		inMap[inorder[i]] = i;
	}
	return buildTreeHelper(preorder,inorder, 0, inorder.size()-1,preIndex,inMap);
}

void displayEdges(TreeNode* root) {
    if (!root) return;
    if (root->left) {
        cout << root->val << " -> " << root->left->val << endl;
        displayEdges(root->left);
    }
    if (root->right) {
        cout << root->val << " -> " << root->right->val << endl;
        displayEdges(root->right);
    }
}

int main(){

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    // Build the tree
    TreeNode* root = buildTree(inorder, preorder);

    // Display the tree as edges
    cout << "Tree Edges (Parent -> Child):" << endl;
    displayEdges(root);

    return 0;

}
