#include<iostream>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}

/*
    Insertion Sort
    space complexity = O(1)
    time complexity = O(n^2)
    best case = O(n)
    worst case = O(n^2)
    use case - for small arrays/partially sorted arrays
*/

void sortInsertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        for (; j >= 0; j--)
        {
            if(arr[j] > temp) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[6] = {10, 12, 45, 1, 23, 90};
    sortInsertion(arr, 6);
    printArr(arr, 6);
}