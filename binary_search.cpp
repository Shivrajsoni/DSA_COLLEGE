// binary search
#include<bits/stdc++.h>
using namespace std;

	int start=0;
	int binarysearch(int arr[],int n,int X){
		int end=n-1;
		int mid;
		while(start<=end){
			int mid=start+(end-start)/2;
			
			if(arr[mid]==X)
			return mid;
				
			else if(arr[mid]<X)
			start=mid+1;
				
			else 
			end=mid-1;
		}
		return 0;
	}
int main(){
	
	int arr[]={1,2,3,4,5,6,7,};
	int n=7;

	return binarysearch(arr,n,2);
	
}
