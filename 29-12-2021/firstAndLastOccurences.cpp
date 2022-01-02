#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){
    int l = 0;
    int h = n-1;
    int res;
    while(l<=h){
        int m = l + (h-l)/2;
        if(arr[m] == key){
            res = m;
            h = m-1;
        }
        else if(arr[m]>key){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return res;
}

int lastOccurence(int arr[], int n, int key){
    int l = 0;
    int h = n-1;
    int r;
    while(l<=h){
        int m = l + (h-l)/2;
        if(arr[m] == key){
            r = m;
            l = m+1;
        }
        else if(arr[m]>key){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return r;
}

int main(){
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<firstOccurence(arr, n, 67)<<"\n";
    cout<<lastOccurence(arr, n, 67);
    return 0;
}