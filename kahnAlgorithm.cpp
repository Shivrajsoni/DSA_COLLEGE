// kahn algorithm

#include<iostream>
using namespace std;

void KahnAlgorithm(vector<int>adj[],int V){
	vector<int>ans;
	vector<int>Indeg(V,0);

	for(int i = 0; i<V;i++){
		for(int j =0;j<adj[i].size();j++){
			Indeg[adj[i][j]]++;
		}
	}

	queue<int>q;
	for(int i =0;i<V;i++){
		if(!Indeg[i])
			q.push(i);

		while(!q.empty()){
			int node  = q.front();
			q.pop();
			ans.push_back(node);

			for(int j = 0; j<adj[i].size(); j++){
				Indeg[adj[node][j]]--;
				
				if(Indeg[adj[node][j]]==0)
					q.push(adj[node][j])

			}
		}
	}

}
