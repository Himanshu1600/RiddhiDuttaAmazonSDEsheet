class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int>mp;
        k= nums.size()-k+1;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto &it:mp){
            if(k>it.second){
                k-=it.second;
            }else{
                return it.first;
            }
        }
        return -1;
    }
};
