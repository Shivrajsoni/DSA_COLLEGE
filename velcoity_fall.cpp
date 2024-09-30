// velocity of ball 

#include<iostream>
using namespace std;

int main(){
	int v;
	cout<<"Enter the velocity in which you move \n";
	cin>>v;
	
	int count=0;
	while(v){
		v/=2;
		count++;
	}
	cout<<"let me guess how much time you will fall in life is  "<<count<< endl<<"  just kidding but it's time how much time how will hit on ground so dont become superman "<<endl;
	
}
