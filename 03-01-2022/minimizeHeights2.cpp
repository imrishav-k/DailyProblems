#include<iostream>
#include<algorithm>
using namespace std;

int minimize(int arr[], int n, int k){
    sort(arr, arr+n);
    int maxel = arr[n-1];
    int minel = arr[0];
    int res = maxel - minel;

    for(int i = 1; i<n; i++){
        if(arr[i]>=k){
            maxel = max(arr[i-1]+k, arr[n-1]-k);
            minel = min(arr[0]+k, arr[i]-k);
            res = min(res, maxel - minel);
        }
    }
    return res;
}

int main(){

    int arr[] = {1, 10, 8, 5};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minimize(arr, n, k);
    return 0;
}