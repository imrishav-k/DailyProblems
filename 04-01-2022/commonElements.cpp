vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
    vector<int> result;
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2 && k<n3){
        if(A[i]<B[j]){
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            if(i>0 && A[i] == A[i-1]){
                i++;
                continue;
            }
            while(k<n3 && B[j] > C[k]){
                k++;
            }
            if(k<n3 && B[j] == C[k]){
                result.push_back(C[k]);
            }
        }
    }
    return result;
}