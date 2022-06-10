class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        vector<pair<int,int>>temp={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto it:temp){
            if(i+it.first>=0 && i+it.first<n && j+it.second>=0 && j+it.second<m ){
                if(grid[i+it.first][j+it.second]=='1' && !vis[i+it.first][j+it.second]){
                    dfs(i+it.first,j+it.second,n,m,grid,vis);
                }
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    dfs(i,j,n,m,grid,vis);
                    result++;
                }   
            }
        }
        return result;
    }
};
