// spiral form -->level Order Traversal
#include<iostream>
using namespace std;

void res(vector<vector<int>>result,Node *l1){
	queue<Node *>q;
	if(root ==NULL){
		return result;
	}
	bool LtoR = true;

	q.push(l1);
	while(!q.empty()){
		int n = q.size();
		vector<int>row(n);
		for(int i =0;i<n;i++){
			Node *temp = q.front();
			q.pop();
			int index = (LtoR) ?i:(n-i-1);
			row[index] = temp->val;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		LtoR = !LtoR;
		res.push_back(row);

	}
	return res;
}

int main(){

}
