//Implementing Binary Search Time Complexity is O(log n).

#include<iostream>

using namespace std;

void readArray(int array[], int size){
    cout << "Enter the Elements of the Array : "<< endl;
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
}

int binarySearch(int array[], int size, int target){
    int start = 0; 
    int end = size - 1;
    int mid;

    while(start <= end){
        mid = start + (end - start) / 2;

        if(array[mid] == target){
            return mid;
        }

        if(array[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int size, target, index;
    cin >> size;
    int array[size];
    readArray(array, size);
    cout << "Enter the target Number " << endl;
    cin >> target;

    index = binarySearch(array, size, target);

    cout << "Target Present at index " << index << endl;

}