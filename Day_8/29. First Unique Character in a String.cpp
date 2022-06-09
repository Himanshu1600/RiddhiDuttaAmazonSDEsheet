class Solution {
public:
    int firstUniqChar(string s) {
       /* map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;*/
        int n=s.size();
        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(count[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
