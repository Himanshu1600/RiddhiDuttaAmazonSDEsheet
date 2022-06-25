class Solution {
public:
    bool ispossible(int mid,vector<int>&wt,int days){
        int cnt=1;
        long long int currsum=0;
        for(int i=0;i<wt.size();i++){
            if((currsum+wt[i])>mid){
                cnt++;
                currsum=0;
            }
            currsum+=wt[i];
        }
        if(cnt<=days) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left=1;
        int right=0;
        for(auto it:weights){
            left=max(left,it);
            right+=it;
        }
        while(left<right){
            int mid= (left+right)/2;
            if(ispossible(mid,weights,days)){
                right=mid;
                //cout<<right<<"#"<<"\n"
            }else{
                left=mid+1;
            }
        }
        return right;
    }
};
