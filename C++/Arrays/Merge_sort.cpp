#include<iostream>
using namespace std;

void merge(int *arr, int s ,int e){
    int mid = s + (e-s)/2;
    //length of 1st array 
    int len1 = mid - s + 1;
    //length of 2nd array 
    int len2 = e - mid;

    //making 2 new array 
    int *first = new int[len1];
    int *second = new int[len2];

    //copy value
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex  = s;
    while(index1 < len1 && index2 <len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while ( index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while ( index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    // we have to dlt new made array otherwise array leak problem may be coem
    delete []first;
    delete []second;


}

void mergesort(int *arr, int s , int e){
    int mid = s+ (e-s)/2;
    //base case
    if (s>=e){
        return;
    }
    //left wale part ko sort karna
    mergesort(arr,s,mid);
    //right wale part ko sort karna
    mergesort(arr,mid+1,e);
    //merge both right and left part
    merge(arr,s,e);

}

int main(){
    int arr[5] = {2,5,1,6,9};
    int n = 5;
    mergesort(arr,0,n-1);
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}