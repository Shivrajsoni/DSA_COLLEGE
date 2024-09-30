// find sum in arr
#include<iostream>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5,6,7,8};
	int n=8;
	int a,b;
	cout<<"Enter the two element you have find sum of "<<endl;	
	cin>>a>>b;
	int x=a+b;
	int sum=0;
	cout << "sum is "<< a+b ;
	
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	for(int i=0;i<n;i++){
		if( (sum-x)==arr[i])
		cout<<"found at index"<<i<<endl;
	}

	
}
