class Solution {
public:
    void solve(int ind,vector<string>&res,string &digit,string temp,vector<string>&result){
        if(ind==digit.size()){
            if(temp.size())
                result.push_back(temp);
            return;
        }
        for(auto it:res[digit[ind]-'0'-2]){
            temp+=it;
            solve(ind+1,res,digit,temp,result);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>res={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        string temp="";
        solve(0,res,digits,temp,result);
        return result;
    }
};
