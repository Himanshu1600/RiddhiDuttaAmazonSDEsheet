vector <int> bottomView(Node *root) {
    queue<pair<Node*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    vector<int>result;
    while(!q.empty()){
        Node* temp=q.front().first;
        int level=q.front().second;
        q.pop();
        mp[level]=temp->data;
        if(temp->left){
            q.push({temp->left,level-1});
        }
        if(temp->right){
            q.push({temp->right,level+1});
        }
    }
    for(auto it:mp){
        result.push_back(it.second);
    }
    return result;
}
