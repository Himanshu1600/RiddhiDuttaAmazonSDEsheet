class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefix=0;
        int suffix=0;
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            prefix= (prefix?prefix:1)*nums[i];
            suffix= (suffix?suffix:1)*nums[n-i-1];
            result=max(result,max(prefix,suffix));
        }
        return result;
    }
};
