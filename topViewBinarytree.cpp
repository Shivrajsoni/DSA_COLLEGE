// Top view
#include<iostream>
using namespace std;

vector<int> topView(Node* root){
	vector<int>result;
	if(!root)
		return result;

	//first node at each horizontal distance(hd)
	map<int,int>topNodes;

	queue<<pair<Node*,int>>q;
	q.push({root,0});

	while(!q.empty()){
		auto nodehd = q.front();
		Node *node  = nodehd.first;
		int hd = nodehd.second;
		q.pop();

		if(topNodes.find(hd)==topNodes.end()){
			topNodes[hd] = node->data;
		}
		if(node->right){
			q.push({node->right,hd+1});
		}
		if(node->left){
			q.push({node->left,hd-1});
		}
	int main(){

	}
