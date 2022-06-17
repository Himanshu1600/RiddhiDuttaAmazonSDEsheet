#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>result;
        pair<int,int> temp;
        temp=make_pair(intervals[0][0],intervals[0][1]);
        for(int i=1;i<n;i++){
            if(temp.second>=intervals[i][0]){
                if(temp.second<intervals[i][1]){
                    temp.second=intervals[i][1];
                }
            }else{
                vector<int>subinterval;
                subinterval.push_back(temp.first);
                subinterval.push_back(temp.second);
                result.push_back(subinterval);
                temp=make_pair(intervals[i][0],intervals[i][1]);
            }
        }
        vector<int>subinterval;
        subinterval.push_back(temp.first);
        subinterval.push_back(temp.second);
        result.push_back(subinterval);

        return result;
    }
};
