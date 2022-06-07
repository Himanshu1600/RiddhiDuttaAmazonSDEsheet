class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int elem1=INT_MIN;
        int elem2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            
            if(elem1==nums[i]){
                cnt1++;
            }else if(elem2==nums[i]){
                cnt2++;
            }else if(cnt1==0){
                elem1=nums[i];
                cnt1++;
            }else if(cnt2==0){
                elem2=nums[i];
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elem1){
                cnt1++;
            }
            if(nums[i]==elem2){
                cnt2++;
            }
        }
        if(cnt1> n/3 && cnt2>n/3){
            return {elem1,elem2};
        }else if(cnt1>n/3){
            return {elem1};
        }else if(cnt2>n/3){
            return {elem2};
        }else{
            return {};
        }
    }
};
