class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,int &color){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==color||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=color;
        return 1 + dfs(i+1,j,grid,color)+dfs(i,j+1,grid,color)+dfs(i-1,j,grid,color)+dfs(i,j-1,grid,color);
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        int color=2;
        unordered_map<int,int>mp;
        mp[0]=0;
        int n=grid.size();
        int m=grid[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mp[color]=dfs(i,j,grid,color);
                    result=max(result,mp[color]);
                    color++;
                }
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<"#"<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int temp=1;
                    unordered_set<int>st;
                    if((i+1)<n){
                        st.insert(grid[i+1][j]);
                    }
                    if((j+1)<m){
                        st.insert(grid[i][j+1]);
                    }
                    if((i-1)>=0){
                        st.insert(grid[i-1][j]);
                    }
                    if((j-1)>=0){
                        st.insert(grid[i][j-1]);
                    }
                    for(auto it:st){
                        temp+=mp[it];
                    }
                    result=max(result,temp);
                }
            }
        }
        return result;
    }
};
