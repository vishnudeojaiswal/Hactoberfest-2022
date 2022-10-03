#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotindex= s+count;
    swap(arr[pivotindex],arr[s]);
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]){
            i++;
        }
        while(arr[j]>arr[pivotindex]){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}

void Quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    Quicksort(arr,s,p-1);
    Quicksort(arr,p+1,e);
}

int main(){
    int arr[]={7,44,3,64,112,34};
    int n= (sizeof(arr)/sizeof(arr[0]));
    Quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}