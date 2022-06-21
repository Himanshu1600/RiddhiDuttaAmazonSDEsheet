class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     int profit=0;
    //     int i=0;
    //     while(i<n){
    //         while(i<(n-1)&& prices[i+1]<=prices[i]) i++;
    //         int buy=prices[i];
    //         while(i<(n-1)&& prices[i+1]>prices[i]) i++;
    //         int sell = prices[i];
    //         profit+= sell -buy;
    //         i++;
    //     }
    //     return profit;
    // }
    
    // second approach
    
    int maxProfit(vector<int>& prices){
        int n=prices.size();
        int profit=0;
        for(int i=1;i<n;i++){
            if((prices[i]-prices[i-1])>0){
                profit+= (prices[i]-prices[i-1]);
            }
        }
        return profit;
    } 
};
