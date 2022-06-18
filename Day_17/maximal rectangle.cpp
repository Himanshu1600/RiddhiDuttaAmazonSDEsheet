class Solution {
public:
    int findmaxi(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        int res=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() &&(i==n || arr[i]<=arr[st.top()])){
                int h=arr[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }else{
                    width=i-st.top()-1;
                }
                res=max(res,h*width);
            }
            st.push(i);
        }
        return res;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>dp(m,0);
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    dp[j]+=1;
                }else{
                    dp[j]=0;
                }
            }
            result=max(result,findmaxi(dp));
        }
        return result;
    }
};
