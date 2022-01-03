#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    
    vector<int> pair;
    pair = intervals[0];
    for(int i = 1; i<intervals.size(); i++){
        if(pair[1]>=intervals[i][0]){
            pair[1] = max(pair[1], intervals[i][1]);
        }
        else{
            result.push_back(pair);
            pair = intervals[i];
        }
    }
    result.push_back(pair);
    return result;
}

int main(){
    vector<vector<int>> intervals {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = merge(intervals);
    for(int i = 0;i < result.size(); i++){
        for(int j = 0; j<2; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}