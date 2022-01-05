bool subArrayExists(int arr[], int n)
    {
        //Your code here
        int prefixSum = 0;
        unordered_set<int> s;
        for(int i = 0; i<n; i++){
            prefixSum += arr[i];
            if(prefixSum == 0){
                return true;
            }
            if(s.find(prefixSum) != s.end()){
                return true;
            }
            s.insert(prefixSum);
        }
        return false;
    }