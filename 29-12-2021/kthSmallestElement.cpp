#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int kthSmallest(int arr[], int n, int k){
    sort(arr, arr+n);
    return arr[k-1];
}

int kthSmallestHeap(int arr[], int n, int k){
    if(k<n-k+1){
        priority_queue<int, vector<int>, greater<int>> pq;//1,2,3,6,7,8,10,12,13
        for(int i = 0; i<n; i++){
            pq.push(arr[i]);
        }
        k--;
        while(k--){
            pq.pop();
        }
        int res = pq.top();
        return res;
    }
    else{
        priority_queue<int> pq; // 13,12,10,8,7,6,3,2,1
        for(int i = 0; i<n; i++){
            pq.push(arr[i]);
        }
        int i = n-k;
        while(i--){
            pq.pop();
        }
        int res = pq.top();
        return res;
    }
}

int main(){
    int k = 8;
    int arr[] = {8,1,3,2,6,7,10,12,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kthSmallestHeap(arr, n, k);
    return 0;
}