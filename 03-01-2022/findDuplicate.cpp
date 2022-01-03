#include<iostream>

using namespace std;

int findDup(int arr[], int n){
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);

    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
}

int main(){
    int arr[] = {6,6,6,4,2,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findDup(arr, n);
    return 0;
}