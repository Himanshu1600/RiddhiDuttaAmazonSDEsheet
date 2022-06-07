class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum=INT_MAX;
        int maxsum=INT_MIN;
        int totalsum=0;
        int possum=0;
        int negsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
            possum+=nums[i];
            negsum+=nums[i];
            maxsum=max(maxsum,possum);
            if(possum<0) possum=0;
            minsum=min(minsum,negsum);
            if(negsum>0) negsum=0;
        }
        if(totalsum==minsum) return maxsum;
        return max(maxsum,totalsum-minsum);
    }
};
