class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        for(int i=0;i<points.size();i++){
            double res= (points[i][0]*points[i][0])+ (points[i][1]*points[i][1]);
            res = (double)sqrt(res);
            pq.push({res,i});
        }
        vector<vector<int>>res;
        while(k--){
            auto it=pq.top().second;
            pq.pop();
            res.push_back(points[it]);
        }
        return res;
    }
};
