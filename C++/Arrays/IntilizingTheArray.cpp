//Program to intialize the array with the same type of element.

#include<iostream>
using namespace std;

int main(){
    int arr[100];

    fill_n(arr, 100, 1); //fill_n is a function used to fill the all the blocks of the array.

    for(int i = 0; i < 100; i++){
        cout << arr[i] << " ";
    }

    return 0;
}