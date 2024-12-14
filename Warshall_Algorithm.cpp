
//Initialize the solution matrix same as the input graph matrix as a first step. 
//Then update the solution matrix by considering all vertices as an intermediate vertex. 
//The idea is to pick all vertices one by one and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
//When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. 
//For every pair (i, j) of the source and destination vertices respectively, there are two possible cases. 
//k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is. 
//k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j], if dist[i][j] > dist[i][k] + dist[k][j]

#include<iostream>
using namespace std;


void WarshallAlgorithm(int dist[][V]){
	int i,j,k;
	for(int k = 0;k<V;k++){
		for(int j = 0 ;j <V;j++){
			for(int i = 0; i<V ;i++){
				if(dist[i][j]>dist[i][k]+dist[k][j] && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main(){

}
