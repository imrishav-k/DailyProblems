#include<iostream>
#include<climits>
using namespace std;

int kadane(int arr[], int n){
    int ms = INT_MIN;//maximum sum
    int cs = 0;//current sum (seen so far)

    for(int i = 0;i<n; i++){
        cs += arr[i];
        if(cs<arr[i]){
            cs = arr[i];
        }
        if(ms<cs){
            ms = cs;
        }
    }
    return ms;
}

int main(){
    int arr[] = {1, 2, 3, -2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kadane(arr, n);
}