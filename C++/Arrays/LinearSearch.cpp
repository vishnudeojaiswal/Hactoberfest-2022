//Program to implement Linear search Algo.

#include<iostream>
using namespace std;

void readArray(int array[], int size){
    for(int i = 0 ; i < size; i++){
        cin >> array[i];
    }
}

int linearSearch(int array[], int size, int target){

    for(int i = 0; i < size; i++){
        if(target == array[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int size, target;
    cin >> size;
    int array[size];
    readArray(array, size);
    cin >> target;

    cout << "Element found at index " << linearSearch(array, size, target);

    return 0;
}