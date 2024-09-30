// single link list creation
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int x){
			int data=x;
			Node *next=NULL;
		}
};

class LinkList{
	public:
		Node *head=NULL;
		void push_at_start(int x){
			head=new Node(x);
		}
		// insertion  at head pointer
		void push_at_head(int x){
			Node *temp=new Node(x);
			temp->next=head;
			head=temp;
		}
		// insertion at tail
		void push_at_end(int x){
			Node *temp=new Node(x);
			Node *tail=head;
			while(tail->next!=NULL){
				tail=tail->next;
			}
			tail->next=temp;
			temp->next=NULL;// redeclaring it 
		}
		// inserting at any position
		void push_at_index(int x,int ind){
			ind--;
			Node * root=head;
			while(ind--){
				root=root->next;
			}
			Node *temp=new Node(x);
			temp->next=root->next;
			root->next=temp;	
		}
		// deleting from start
		void delete_at_start(){
			Node *temp=head;
			head=head->next;
			delete temp;
		}
		// delete from end
		void delete_at_end(){
			Node *prev=NULL;
			Node *temp=head;
			while(temp->next!=NULL){
				prev=temp;
				temp=temp->next;
			}
			delete temp;
			prev->next=NULL;
		}
		// DELETE FROM anywhere given index
		void delete_at_index(int i){
			Node *prev=NULL;
			Node *temp=head;
			while(--i){
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
			delete temp;
		}
		// search from anywhere 
		void search(int data){
			Node *temp=head;
			while(head->next!=NULL){
				if(head->data==data){
					cout<<"found the element ";
				}
				else{
					head=head->next;
				}
			}
		}
		// print all element
		void print(){
			Node *root=head;
			while(root->next!=NULL){
				cout <<"head->data is "<< root->data<<endl;
				root=root->next;
			}
			
		}
};
int main(){
	LinkList l;
	l.push_at_start(5);
	l.push_at_head(12);
	l.print();
}
