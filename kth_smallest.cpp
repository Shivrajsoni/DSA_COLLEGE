#include<iostream>
using namespace std;


void Heapify(int arr[],int n,int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<n && arr[largest]<arr[left]){
        left = largest;

    }
    if(right<n && arr[largest]>arr[right]){
        right = largest;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        Heapify(arr,n,largest);
    }
}
void BuildHeap(int arr[],int n){
    for(int i=n/2 -1;i>=0;i--){
        Heapify(arr,n,i);
    }
}


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n;
	cout<<"Enter the number of array"<<endl;
	cin>>n;
	
	cout<<"Enter the elements of array"<<endl;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
    printArray(arr,n);

    int x;
    cout<<"ENter your Kth smallest NUmber "<<endl;
    cin>>x;
    BuildHeap(arr,x);
    for(int i=x;i<n;i++){
        if(arr[0]>arr)
    }

	
}