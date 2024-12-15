#include<iostream>
using namespace std;

:
vector<int>BFSGraph(int V, vector<int>adj[]){
	queue<int>q;
	vector<bool>visited(V,0);
	q.push(0);
	visited[0] =1;
	
	vector<int>ans;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		ans.push_back(node);

		for(int j =0;j<=adj[node].size();j++){
		if(visited[node][j]!=1){
			q.push(adj[node][j]);
			visited[node][j]
		}
	}
	}

}


int main(){

}
