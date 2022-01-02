#include<iostream>
#include<unordered_set>
using namespace std;

void findIntersection(int arr1[], int arr2[], int n1, int n2, int arr3[]){
    unordered_set<int> s;
    for(int i = 0;i<n1;i++){
        s.insert(arr1[i]);
    }
    int j = 0;
    for(int i = 0; i<n2; i++){
        if(s.find(arr2[i])!=s.end()){
            arr3[j] = arr2[i];
            j++;
            s.erase(arr2[i]);
        }
    }
}

int main(){
    int arr1[] = {1,2,3,4,5,6,7,8};
    int arr2[] = {3,2,5,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[10000];
    for(int i = 0; i<10000; i++){
        arr3[i] = -1;
    }
    findIntersection(arr1, arr2, n1, n2, arr3);
    for(int i = 0; arr3[i]!=-1; i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}