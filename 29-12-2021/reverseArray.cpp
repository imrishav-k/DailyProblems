#include<iostream>
using namespace std;

void printArr(int arr[], int size);
void reverseArrIterative(int arr[], int size);
void reverseArrRecursive(int arr[], int start, int end);


int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);
    reverseArrRecursive(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}

void reverseArrIterative(int arr[], int size){
    int start = 0;
    int end = size - 1;
    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void reverseArrRecursive(int arr[], int start, int end){
    if(start>end){
        return;
    }
    swap(arr[start], arr[end]);
    reverseArrRecursive(arr, start+1, end-1);
}

void printArr(int arr[], int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}