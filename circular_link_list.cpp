// circular link list 
// if we want to search a link list we should store
#include<bits/stdc++.h>
using namespace std; 
void detectcircular(Node *head){
	vector<int>ans;
	while(head->next!=NULL){
		ans.push_back(head->next);
		head=head->next;
	}
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(head->next==arr[i]){
			cout<<"its a circular link list"<<endl;
		}
	}
}
int main(){
	
	
}
