 void CoranaSpread(vector<vecto<int>>adj){
	 int r = adj.size();
	 int c = adj[0].size();

	 queue<pair<int,int>>q;

	 for(int i=0;i<r;i++){
		 for(int j=0;j<c;j++){
			 if(adj[i][j]==2)
				 q.push({i,j});
		 }
	 }

	 int timer =0;
	 while(!q.empty()){
		 timer ++;
		 int curr_patient = q.size();
		 while(curr_patient--){
			 int i = q.front().first;
			 int j = q.front().second;

			 q.pop();
			 
			 int row ={-1,1,0,0};
			 int col = {0,0,-1,1};
			 for(int k =0;k<4;k++){
				 if(valid([i+row[k]],j+col[k]) && adj[i+row[k]][j+col[k]]){
					 q.push({i+row[k],j+col[k]});
				 }
			 }


		 }

	 }
 }
