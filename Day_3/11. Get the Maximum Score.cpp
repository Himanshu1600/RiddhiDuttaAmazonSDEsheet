class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        long long int s1=0;
        long long int s2=0;
        while(i<n || j<m){
            if(i<n && (j==m|| nums1[i]<nums2[j])){
                s1+=nums1[i];
                i++;
            }else if(j<m&& (i==n||nums2[j]<nums1[i])){
                s2+=nums2[j];
                j++;
            }else{
                s1=s2= max(s1,s2)+nums1[i];
                i++;
                j++;
            }
        }
        return max(s1,s2)%1000000007;
    }
};
