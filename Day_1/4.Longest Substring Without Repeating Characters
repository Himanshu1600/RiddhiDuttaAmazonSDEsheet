class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int n=s.size();
        int left=0;
        int result=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                left=max(mp[s[i]]+1,left);
            }
            mp[s[i]]=i;
            result=max(result,i-left+1);
        }
        return result;
    }
};
