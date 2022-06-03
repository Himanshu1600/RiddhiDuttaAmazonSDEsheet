class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        while(st.size()>3){
            st.erase(st.begin());
        }
        if(st.size()<3){
            if(st.size()==1){
                return *st.begin();
            }
            st.erase(st.begin());
        }
        return *st.begin();
    }
};
