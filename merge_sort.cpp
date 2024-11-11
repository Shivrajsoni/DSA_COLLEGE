#include<iostream>
using namespace std;

void mergeS(int arr[],int start,int mid ,int end){
    int n1= mid-start+1;
    int n2 = end-mid;

    int l[n1],m[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[start +i];
    }
    for(int j=0;j<n2;j++){
        m[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=start;
    while(i<n1 && j<n2 ){
        if(l[i]<=m[j]){
            arr[k]=l[i];
        }
        else{
            arr[k]=m[j];
        }
        i++;
        j++;
        k++;
    }
    while(i<n1){
        arr[k]= l[i];
        i++;
        k++;

    }
    while(j<n2){
        arr[k]=m[j];
        j++;
        k++;
    }

// sort  function and then combine it 

}

void MergeSort(int arr[],int low,int high){
    while(low<=high){
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        mergeS(arr,low,mid,high);

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
    MergeSort(arr,0,n-1);

    printArray(arr,n);
}