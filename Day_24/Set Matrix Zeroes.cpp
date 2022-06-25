class Solution {
public:
    void putzeros(int i,int j,vector<vector<int>>&mat){
        for(int x=0;x<mat[0].size();x++){
            mat[i][x]=0;
        }
        for(int x=0;x<mat.size();x++){
            mat[x][j]=0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int i=0;
        int j=0;
        int n=matrix.size();
        int m=matrix[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            putzeros(it.first,it.second,matrix);
        }
    }
};
