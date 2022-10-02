//Program to fint the sum of the array.

#include<iostream>
using namespace std;

void readArray(int array[], int size){

    for(int i = 0 ; i < size; i++){
        cin >> array[i];
    }
}

int sumOfArray(int array[], int size){
    int sum = 0;

    for(int i = 0 ; i < size; i++){
        sum += array[i];
    }
    
    return sum;
}

int main(){

    int size;
    cin >> size;
    int array[size];
    readArray(array, size);

    cout << "Sum of the Given Elemnts is = " << sumOfArray(array, size) << endl;

    return 0;
}