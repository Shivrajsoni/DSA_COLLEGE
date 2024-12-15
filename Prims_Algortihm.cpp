// Prims Algorithm
#include<iostream>
using namespace std;

typedef <pair<int,pair<int,int>>> pii;

int spanningTree(int V,vector<vector<int>>adj[]){
	priority_queue<pii,vector<pii>,greater<pii>>;

	vector<bool>isMst(V,0);
	vector<int>parent(V);
	int cost =0;
	p.push({0,{0,-1}});

	while(!p.empty()){
		int wt = p.top().first;
		int node = p.top().second;
		int par = p.top().second.second;

		pq.pop();

		if(!isMst[node]){
			isMst[node] =1;
			cost+=wt;
			parent[node] = par;

			for(int j =0;j<adj[node].size();j++){
				if(!isMst[adj[node][j][0]]){
					pq.push({adj[node][j][1],{adj[node][j][0],node}});
				}
			}
		}

	}
}
int main(){

}
