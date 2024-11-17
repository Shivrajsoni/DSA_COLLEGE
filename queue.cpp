// queue using linklist
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
 
class queue{
	public:
		Node *front,rear;
		queue(){
			front=NULL;
			rear=NULL;
		}
		bool isEmpty(){
			return front==NULL;
		}
		void push(int x){
			if(isEmpty()){
				front =new Node(x);
				rear=front;
				return;
			}
			else if{
			rear->next=new Node(x);
			rear=rear->next();
			}
		}
		void pop(){
			Node *temp=front;
			fron=front->next;
			delete temp;
			return ;
		}
		
};
