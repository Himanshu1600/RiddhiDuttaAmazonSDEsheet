class Solution {
public:
    void dfs(int ind,vector<vector<int>>&adj,vector<int>&vis){
        vis[ind]=1;
        for(auto it:adj[ind]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        if(m<(n-1)) return -1;
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count-1;
    }
};
