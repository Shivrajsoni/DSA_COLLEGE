// Djikstra Algorithm

// time complexity of 
//O((V+E)logV), where V is the number of vertices and E is the number of edges.


//The graph is represented as an adjacency list, where adj[u] contains pairs {v, w} meaning an edge from u to v with weight w.
#include<iostream>
using namespace std;

typedef pair<int,int> pii;


vector<int>dijkstra(int V, vector<vector<pii>>& adj, int source){
	priority_queue<pii,vector<pii>,greater<pii>> pq;

	vector<int> dist(V,INT_MAX);
	dist[source] = 0;
	pq.push({0,source});

	while(!pq.empty()){
		int d = pq.top.first // distance from the top node
		int u = pq.top.second // current node
		pq.pop();

		// checking the neighbour
		for(auto &neighbour : adj[u]){
			int v = neighbour.first;
			int weight = neighbour.second;

			// relaxation step
			if(dist[u]+weight < dist[v]){
				dist[v] = dist[u] + weight ;
				pq.push({dist[v],v});
			}
		}
	}
	return dist;

}

int main(){
	int V =5;
	vector<vector<pii>> adj(V);
	    // Add edges (u, v, w): u -> v with weight w
	adj[0].push_back({1, 10});
	adj[0].push_back({4, 3});
	adj[1].push_back({2, 2});
	adj[2].push_back({3, 9});
	adj[4].push_back({1, 1});
	adj[4].push_back({2, 8});

	int source = 0; // Source node
	vector<int> distances = dijkstra(V, adj, source);

	// Print the shortest distances
	cout << "Shortest distances from source " << source << ":\n";
	for (int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << " : " << distances[i] << endl;
	}

	return 0;

}
