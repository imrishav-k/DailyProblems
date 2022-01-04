class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int h = 1;
        int res = 0;
        while(h<prices.size()){
            while(h<prices.size() && prices[h]<prices[l]){
                l = h;
                h++;
            }
            if(h>=prices.size()){
                break;
            }
            if(prices[h] - prices[l]>res){
                res = prices[h] - prices[l];
            }
            h++;
        }
        return res;
    }
};