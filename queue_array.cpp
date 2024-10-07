
#include<bits/stdc++.h>
using namespace std;
class queues{
	public:
	int *arr;
	int s;
	int front;
	int rear;
	
	queues(int size){
	    arr=new int[size];
	    s=size;
		front=rear=-1; 
	}
	void enqueue(int x){
	if(rear==s-1){
	    cout<<"Queue is full "<<endl;
	}
		
	if(front==-1){
		front++;
	}
	
	rear++;
	arr[rear]=x;
		
	}
	
	void deque(){
	    front++;
	}
	void display() {
        if (front == -1 || front > rear) {  // Check if the queue is empty
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
	
	
};

int main(){
	queues q(4);
	
	q.enqueue(11);
	q.enqueue(31);	
	q.enqueue(41);
	q.enqueue(1);
	
	q.display();
	q.deque();
	q.display();
}