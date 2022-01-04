#include<iostream>

long long countAndMerge(long long arr[], long long l, long long m, long long r){
    long long n1 = m-l+1, n2 = r-m;
    long long left[n1];
    long long right[n2];
    for(long long i = 0; i<n1; i++){
        left[i] = arr[l+i];
    }
    for(long long i = 0; i<n2; i++){
        right[i] = arr[m+1+i];
    }
    long long res = 0, i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
            res += (n1-i);
        }
        k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
    return res;
}

long long int countInv(long long arr[], long long l, long long r){
    long long res = 0;
    if(l<r){
        long long m = l + (r-l)/2;
        res += countInv(arr, l, m);
        res += countInv(arr, m+1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main(){
    long long arr[]= {2,4,1,3,5};
    long long n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<countInv(arr, 0, n-1);
    return 0;
}