//Program to swap the alternate elements of the given Arrays.

#include<iostream>
using namespace std;

void readArray(int array[], int size){
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }
}

void prinArray(int array[], int size){
    for(int i =0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void swapAlternative(int array[], int size){
    int first = 0, next = 1;

    while(next < size){
        int temp = array[first];
        array[first] = array[next];
        array[next] = temp;
        first += 2;
        next += 2;
    }
}

int main(){

    int size;
    cin >> size;
    int array[size];
    readArray(array, size);

    cout << "Orignal Array -> " << endl;
    prinArray(array,size);

    cout << "Alternative Swaped Array -> " << endl;
    swapAlternative(array, size);
    prinArray(array, size);

}