// missing element

#include<iostream>
using namespace std;
int main(){
	int arr[]={2,3,4,5,6,8};
	int n=6;
	
	for(int i=0;i<n;i++){
		int a=arr[i]&1;
		int b=arr[i+1]&1;
		if(a==b)
		{
			cout<<"missing elment is "<<arr[i]+1<<"and its index is "<<i+1<<endl;
		}
	}
	return 0;
}
