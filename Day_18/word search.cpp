class Solution {
public:
    bool findword(int i,int j,vector<vector<char>>&grid,string word,int k,vector<vector<int>>&vis){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
            return false;
        }
        if(k==word.size()) return true;
        vector<pair<int,int>>temp={{1,0},{-1,0},{0,1},{0,-1}};
        vis[i][j]=1;
        for(auto it:temp){
            int x=i+ it.first;
            int y=j+it.second;
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&& !vis[x][y]){
                if(grid[x][y]==word[k]){
                    if(findword(x,y,grid,word,k+1,vis)) return true;
                }
            }
        }
        vis[i][j]=0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m= board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(findword(i,j,board,word,1,vis)) return true;
                }
            }
        }
        return false;
    }
};
