#include<iostream>
using namespace std;

void DFSTraversal(int node,vector<int>adj[],vector<bool>visited,vector<int>&ans){
	visited[node] = 1;
	ans.push_back(node);

	for(int j =0;j<adj[node].size();j++){
		if(!visited[node][j]){
			DFSTraversal(adj[node][j],adj,visited,ans);
		}
	}

}

int main(){
	int V;
	vector<bool>visited(V,0);
	vector<int>ans;
	

}
