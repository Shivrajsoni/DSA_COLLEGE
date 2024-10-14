// heap sort


// #include<bits/stdc++.h>
#include<iostream>
#include <chrono> // To measure time
#include <cstdlib> // For generating random numbers
#include <fstream> // To save results to a file

using namespace std;
using namespace std::chrono;


// heapify
void heapify(int *arr,int n,int i){

	int largest=i;
	int left=2*i+1;
	int right = 2*i+2;
	
	if(  left<n  && arr[largest]<arr[left]  ){
		largest=left;
	}
	else if( right<n && arr[largest]<arr[right] ){
		largest = right;
	}
	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
	
}
// build heap
void Buildheap(int *arr,int n){
	
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
}
void HeapSort(int *arr,int n){
	Buildheap(arr,n);
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0); // heapify the reduced heap
	}
}
// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; ++i)
//         cout << arr[i] << " ";
//     cout << endl;
// }
void generateRandomArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}


int main(){

    ofstream outfile("heapsort_times.csv");
    outfile<<"Array Size,Time (microseconds)\n";

    for(int n=1000;n<=100000;n+=1000){
        int *arr=new int[n];
        generateRandomArray(arr,n);

        // measure time taken by heap Sort
       auto start = high_resolution_clock::now();
        HeapSort(arr,n);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();


        cout<<"Array size:"<<n<<", Time taken: "<<duration<<" microseconds"<<endl;

        // save to file 
        outfile<<n<<","<<duration<<"\n";


        delete[] arr; // clean up memory
    }

    outfile.close();
    return 0;

	
	
}