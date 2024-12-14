// we have to write an algorothm which will give max value at each level of binary treee
#include<iostream>
using namespace std;

Class Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

void helper(vector<int>&res, Node *root,int d){

	if(d == res.size()){
		res.push_back(root->data);
	}

	res[d] = max(res[d],root->data);
	helper(res,root->left,d+1);
	helper(res,root->right,d+1);
}

// 2nd method 
	
void helper2(vector<int>res,Node *root){
	queue<Node *>q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		int maxi = INT_MIN;
		for(int i = 0;i<n;i++){
			Node *temp = q.front();
			q.pop();
			maxi =max(maxi,temp->data);
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		res.push_back(maxi);
	}
	return res;
}







int main(){
	vector<int>res;
	helper(res,root,0);
	return res;
}
