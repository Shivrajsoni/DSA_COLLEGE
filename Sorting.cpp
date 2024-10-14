#include<bits/stdc++.h>

using namespace std;

// void insertionSort(int *arr, int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;
        
//         // Move elements of arr[0..i-1] that are greater than key
//         // to one position ahead of their current position
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//     }
// }

// void selectionSort(int *arr,int n){
// 	for(int i=0;i<n-1;i++){
		
// 		int index=i;
		
// 		for(int j=i+1;j<n;j++){
// 			if(arr[j]<arr[index]){
// 				index=j;
// 			}
			
// 		}
// 		if(index!=-i){
// 			swap(arr[index],arr[i]);
			
// 		}
// 	}
// }




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
	

	quickSort(0,n)

	// selectionSort(arr,n);
	printArray(arr,n);

	
}