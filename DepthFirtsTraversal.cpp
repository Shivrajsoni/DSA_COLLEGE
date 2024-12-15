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
// detecting the cycle 
void detectCycle(int node,int parent,vector<int>adj[],vector<bool>&visited){
	visited[node] = 1;
	for(int j =0;j<adj[node].size();j++){
		if(parent ==adj[node][j]==1){
			continue;
		}
		if(visited[adj[node][j]] ==1){
			return 1;
		}
		if(detectCycle(adj[node][j],node,adj[],visited))
			return 1;
	}
	return 0;
}


int main(){
	int V;
	vector<bool>visited(V,0);
	vector<int>ans;
	

}
