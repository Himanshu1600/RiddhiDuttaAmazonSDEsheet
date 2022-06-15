class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        if(n==0) return 0;
        //char first=needle[0];
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                if(haystack.size()-i>=n){
                    string s = haystack.substr(i,n);
                    if(s==needle) return i;
                }
            }
        }
        return -1;
    }
};
