class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>result(n,-1);
        for(int i=0;i<2*n;i++){
            while(!st.empty()&& nums[i%n]>nums[st.top()%n]){
                result[st.top()%n]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return result;
    }
};
