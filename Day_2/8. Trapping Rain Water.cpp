class Solution {
public:
    int trap(vector<int>& height) {
        
        // T.C= O(n)+O(n)+O(n);
        // S.C= O(2n);
        
        /*int n=height.size();
        int pre=0;
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        for(int i=0;i<n;i++){
            pre=max(pre,height[i]);
            prefix[i]=pre;
        }
        pre=0;
        for(int i=n-1;i>=0;i--){
            pre=max(pre,height[i]);
            suffix[i]=pre;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            height[i]=min(prefix[i],suffix[i])-height[i];
            sum+=height[i];
        }
        return sum;*/
        
        // Best Approach and Optimal approach
        int result=0;
        int l=0;
        int r=size(height)-1;
        int leftmax=0;
        int rightmax=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=leftmax) leftmax=height[l];
                else result+=(leftmax-height[l]);
                l++;
            }else{
                if(height[r]>=rightmax) rightmax=height[r];
                else result+=(rightmax-height[r]);
                r--;
            }
        }
        return result;
    }
};
