vector<vector<int>> verticalTraversal(TreeNode* root) {
    queue<pair<TreeNode*,pair<int,int>>>q;
    vector<vector<int>>result;
    if(root==NULL) return result;
    q.push({root,{0,0}});

    map<int,map<int,multiset<int>>>mp;

    while(!q.empty()){

        TreeNode* temp=q.front().first;
        int level_x=q.front().second.first;
        int level_y=q.front().second.second;
        q.pop();              
        mp[level_x][level_y].insert(temp->val);

        if(temp->left){
            q.push({temp->left,{level_x-1,level_y+1}});
        }

        if(temp->right){
            q.push({temp->right,{level_x+1,level_y+1}});
        }

    }

    for(auto it:mp){
        vector<int>temp;
        for(auto x:it.second){
            temp.insert(temp.end(),x.second.begin(),x.second.end());
        }
        result.push_back(temp);
    }
    return result;
}
