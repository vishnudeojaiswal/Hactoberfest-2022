//Using Array with the functions.

#include<iostream>
using namespace std;

void arrayReturn(int arry[], int size){

    arry[4] = 10;
}

void printArray(int arr[], int size){
    for(int i = 0; i < 5; i++){
        cout << arr[i]; 
    }
}

void printArray(char arr[], int size){
    for(int i = 0; i < 5; i++){
        cout << arr[i]; 
    }
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    char ch[5] = {'a', 'e', 'i', 'o', 'u'};

    printArray(a, 5);
    arrayReturn(a, 5);
    cout <<endl;
    printArray(a, 5);
    cout << endl;
    printArray(ch, 5);

}