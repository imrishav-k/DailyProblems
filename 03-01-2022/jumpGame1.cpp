#include<iostream>

using namespace std;

bool canJump(int arr[], int n){
    int reachable = 0;
    for(int i = 0; i<n; i++){
        if(reachable < i){
            return false;
        }
        reachable = max(reachable, i+arr[i]);
    }
    return true;
}

int main(){
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<canJump(arr, n);
}