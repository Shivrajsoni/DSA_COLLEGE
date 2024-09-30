// stack through link list
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int x){
			data=x;
			next=NULL;
		}
};

class stack{
	public:
		int size;
		Node *top;
		stack(){
			top=NULL;
			size=0;
		}
		void push(int val){
			Node *temp=new Node(val);
			temp->next=top;
			top=temp;
			size++;
		}
		void pop(){
			Node *temp=top;
			top=top->next;
			delete temp;
			size--;
		}
		// size
		int size(){
			return size;
		}
};
int main(){
	
}
