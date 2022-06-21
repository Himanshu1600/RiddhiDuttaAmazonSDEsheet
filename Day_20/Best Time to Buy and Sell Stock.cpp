class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            int diff=prices[i]-mini;
            if(diff>profit){
                profit=diff;
            }
        }
        return profit;
    }
};
