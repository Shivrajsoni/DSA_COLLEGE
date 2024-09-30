// double link list 

class dll{
	public:
		int data;
		Node *prev;
		Node *next;
		dll(int x){
			data=x;
			prev=NULL;
			next=NULL;
		}
		Node *head=NULL;
		// insertion at any point 
		void push(int x,int i){
			Node *temp=head;
			while(i--){
				temp=temp->next;
			}
			Node *temp2=new Node(x);
			temp2->next=temp->next;
			temp->next=temp2;
			temp2->prev=temp;// doubt a?
		}
		void pop(int i){
			Node *temp=head;
			while(--i){
				temp=temp->next;
			}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			
			
		}
};
int main(){
	dll d(3);
	
	
}
