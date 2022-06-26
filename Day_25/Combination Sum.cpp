class Solution {
public:
    void solve(int i,int target,vector<int>&candidates,vector<vector<int>>&result,vector<int>temp){
        if(i==0){
            if(target%candidates[0]==0){
                for(int i=0;i<target/candidates[0];i++){
                    temp.push_back(candidates[0]);
                }
                result.push_back(temp);
            }
            return;
        }
        
        solve(i-1,target,candidates,result,temp);
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i,target-candidates[i],candidates,result,temp);
        }
            
        //result.push_back(temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        int n=candidates.size();
        vector<int>temp;
        solve(n-1,target,candidates,result,temp);
        return result;
    }
};
