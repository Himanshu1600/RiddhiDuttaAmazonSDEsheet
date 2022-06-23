class Solution {
public:
    int solve(int ind,string &s,vector<int>&dp){
        if(ind>=s.size()){
            return 1;
        }
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int res = solve(ind+1,s,dp);
        if(ind<(s.size()-1)&& (s[ind]=='1'|| s[ind]=='2' && s[ind+1]<'7')){
            res+= solve(ind+2,s,dp);
        }
        return dp[ind]=res;
    }
    
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        //int count=0;
        return solve(0,s,dp);
        //return count;
    }
};
