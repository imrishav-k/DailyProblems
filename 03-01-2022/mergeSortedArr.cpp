#include<iostream>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    // int p = 0;
    
    // while(p<n){ 
    //     if(arr1[p]>arr2[0]){
    //         swap(arr1[p], arr2[0]);
    //         int i = 0;
    //         while(arr2[i]>arr2[i+1]){
    //             swap(arr2[i], arr2[i+1]);
    //             i++;
    //         }
    //         p++;
    //     }
    // }
    ///////////////////OPTIMIZED/////////////////
    int gap = (n+m)/2;
    if((n+m)%2){
        gap++;
    }
    while(gap){
        int i = 0;
        int j = gap;
        while(j<n && i<n){
            if(arr1[i]>arr1[j]){
                swap(arr1[i], arr1[j]);
            }
            i++;
            j++;
        }
        j = j-n;
        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                swap(arr1[i], arr2[j]);
            }
            i++;
            j++;
        }
        i = i-n;
        while(j<m && i<m){
            if(arr2[i]>arr2[j]){
                swap(arr2[i], arr2[j]);
            }
            i++;
            j++;
        }
        if(gap%2==0 || gap == 1){
            gap = gap/2;
        }
        else{
            gap = (gap/2)+1;
        }
    }
}

int main(){
    int arr1[] = {1,3,5,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2,4,6,9,10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, n1, n2);
    return 0;
}