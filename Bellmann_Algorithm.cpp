// Non Weighted Djikstra Algorithm (Bellman ALgorithm)
#include<iostream>

using namespace std;
struct Edge{
	int u,v,weight;
};

bool bellmanFord(int V, int E,vector<Edge> & edges,int source){
	vector<int>distance(V,INT_MAX);
	distance[source] = 0;

	// relaxing all edges V-1 TIMES
	for(int i = 1;i<=V-1;i++){
		for(int j = 0;j<E;j++){
			int u = edges[j].u;
			int v = edges[j].v;
			int weight = edges[j].weight;

			// relax all edges if possible
			if(distance[u]!=INT_MAX && distance[u]+weight <distance[v]){
				distance[v] = distance[u]+weight;
			}

		}
	}
	// check for Negative weight cycle 
	for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return false;
        }

	}
	// Print distances from source
	 cout << "Shortest distances from source " << source << ":\n";
	 for (int i = 0; i < V; i++) {
		if (dist[i] == INT_MAX) {
		cout << "Node " << i << " : Infinity" << endl;
		} else {
		 cout << "Node " << i << " : " << dist[i] << endl;
		}
	}

    return true;
}

int main(){
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    vector<Edge> edges;

    // Graph definition: (u, v, w)
    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});

    int source = 0; // Source vertex

    // Run Bellman-Ford algorithm
     bellmanFord(V, E, edges, source);

     return 0;	

}
