
void twoColorProblem(vector<int>adj[],int V){
	// first we will assign all color -1 ,, -->red =0, green =-1 by BFS TRAVERRSAL we can find t
	vector<int>color(V,-1);
	queue<int>q;
	q.push(0);
	color[0]= 0; // red is assigned
	
	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(int j =0;j<adj[node].size();j++){
			if(color[adj[node][j]==-1]){
				color[adj[node][j]] = (colour[node]+1)%2;
				q.push(adj[node][j]);
			}

			if(color[adj[node][j]]==color[node]){
				return 0;
			}
		}
	}
	return 1;
}

// using DFS TRAVERSAL
//

void UsinfDFS(vector<int>adj[],int node, vector<int>&color){

	for(int j = 0;j<adj[node].size();j++){
		if(color[adj[node][j]]==-1){
			color[adj[node][j]] = (color[node] +1)%2;
		}
		else if (!UsinDFS(adj,adj[node][j],color)
			return 0;)
		else if(
		color[adj[node][j]] == color[node]
				return 0;

		)
	}
}


