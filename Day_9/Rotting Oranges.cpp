class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int a=q.size();
            while(a--){
                auto it=q.front();
                q.pop();
                vector<pair<int,int>>temp={{1,0},{-1,0},{0,1},{0,-1}};
                for(auto res:temp){
                    int x= res.first+it.first;
                    int y = res.second+it.second;
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            if(!q.empty()) time++;
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
