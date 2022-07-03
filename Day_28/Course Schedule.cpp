class Solution {
public:
    bool containcycle(int i,vector<vector<int>>&adj,vector<int>&visited,int parent){
        if(visited[i]==1) return true;
        
        if(visited[i]==0){
            visited[i]=1;
            for(auto it:adj[i]){
                if(containcycle(it,adj,visited,i)) return true;
            }
        }
        visited[i]=2;
        
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(containcycle(i,adj,visited,-1)){
                    return false;
                }
            }
        }
        return true;
    }
};
