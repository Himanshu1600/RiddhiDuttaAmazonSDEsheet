class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int first=0;
        int last=nums.size()-1;
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(make_pair(nums[i],i));
        }
        sort(temp.begin(),temp.end());
        while(first<last){
            if(temp[first].first+temp[last].first<target){
                first++;
            }else if(temp[first].first+temp[last].first>target){
                last--;
            }else{
                result.push_back(temp[first].second);
                result.push_back(temp[last].second);
                break;
            }
        }
        return result;
    }
};
