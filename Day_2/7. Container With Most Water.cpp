class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int dist=min(height[left],height[right]);
            result=max(result,(right-left)*dist);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return result;
    }
};
