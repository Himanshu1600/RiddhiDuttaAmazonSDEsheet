class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,l;
        int n=nums.size();
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(l=n-1;l>=0;l--){
            if(nums[l]>nums[i]){
                swap(nums[i],nums[l]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};
