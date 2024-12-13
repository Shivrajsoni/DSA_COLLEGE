#include<iostream>
using namespace std;

class Stack(){
private:
	int *arr;
	int top;
	int top1,top2;

public:
	Stack(int n){
		size = n;
		arr = new int[n];
		top1 =-1;
		top2 = size;
	}

	void push1(int value){
		if(top1+1<top2){
			arr[++top1] = value;
		}else{}
	}

	void push2(int value){
		if(top1+1<top2 && top2<size){
			arr[++top1] = value;
		}else{}
	}
	int pop1(){
		if(top1>=0){
			return arr[top1--];
		}
		else{
			return -1;
		}
	}

	int pop2(){
		if(top2<=size){
			return arr[top2++];
		}
		else{
			return -1;
		}
	}

	void display(){
		
	}
	~Stack(){
		delete[] arr;
	}



int main(){
	stack s1;
	stack s2;
	int arr[]={1,2,3,4,5,6,7,8,9,1};
	int i=0;
	int j =10;
	while(i<j){
		s1.push(arr[i]);
		s2.push(arr[j]);
		i++;
		j--;
	}
	return 0;
}
