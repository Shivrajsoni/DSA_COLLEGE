// problem  to find maximum area in array given
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5,6,7,8};
	int n=8;
//	vector<pair<int,pair<int,int> > >ans;
	int maxi=-1e9;
	int i1=-1;
	int i2=-1;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			int area=((j-i)*abs(arr[i]-arr[j])+(abs(arr[i]-arr[j])*(j-i))/2);
			maxi=max(area,maxi);
			i1=i;
			i2=j;
		}
	}
	cout<<"maximum area is "<<maxi<<"it's from ith coordinate equals to "<< i1 <<"to jth coordinate "<< i2<<endl;
}
