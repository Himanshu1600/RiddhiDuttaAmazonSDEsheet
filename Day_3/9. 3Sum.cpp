class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();
        if(n<3) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int target=0-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(nums[left]+nums[right]<target){
                    left++;
                }else if(nums[left]+nums[right]>target){
                    right--;
                }else{
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    while(left<right && nums[left]==temp[1]){
                        left++;
                    }
                    while(left<right && nums[right]==temp[2]){
                        right--;
                    }
                }
            }
            while(i<n-2 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return result;
    }
};
