#include<iostream>
using namespace std;

Node *Rotation(Node *l,int k){
	// first step 
	Node *head = l1;
	if(!head || !head->next ||k ==0){
		return head;
	}
	int length = 1;
	Node *temp = l1;
	while(temp->next!=NULL){
		temp = temp->next;
		length ++;
	}
	//adding circular dependency
	temp->next = head;

	// finding new Tail 
	int StepToNewHead = length -k;

	Node *newTail = l1;
	for(int i =1;i<=StepToNewHead;i++){
		newTail = newTail->next;
	}

	Node *newHead = newTail->next;
	newTail->next - NULL ; // Breaking Circular Dependency
	return newHead;
}

int main(){

}
