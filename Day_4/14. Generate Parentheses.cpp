class Solution {
public:
    
    void solve(int open,int close,int n,vector<string>&result,string temp){
        if(open==n&&close==n){
            result.push_back(temp);
            return;
        }
        
        if(open<n){
            string s= temp+'(';
            solve(open+1,close,n,result,s);
        }
        
        if(close<open){
            string y=temp+')';
            solve(open,close+1,n,result,y);
        }
       
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp="";
        solve(0,0,n,result,temp);
        return result;
    }
};
