class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis){
        vis[i][j]=1;
        vector<pair<int,int>>temp={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto it:temp){
            int x=i+it.first;
            int y=j+it.second;
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&!vis[x][y]&&board[x][y]=='O'){
                dfs(x,y,board,vis);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'&&!vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O'&&!vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'&&!vis[0][i]){
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O'&&!vis[n-1][i]){
                dfs(n-1,i,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
