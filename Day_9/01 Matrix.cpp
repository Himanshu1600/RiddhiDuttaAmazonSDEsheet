class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>temp={{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto a:temp){
                int s1=it.first+a.first;
                int s2=it.second+a.second;
                if(s1>=0&&s1<n&&s2>=0&&s2<m&& dis[s1][s2]==-1){
                    q.push({s1,s2});
                    dis[s1][s2]=dis[it.first][it.second]+1;
                    mat[s1][s2]=dis[s1][s2];
                }
            }
        }
        return mat;
    }
};
