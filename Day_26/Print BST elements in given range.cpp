void solve(Node* root,int low,int high,vector<int>&result){
    if(root==NULL) return;
    solve(root->left,low,high,result);
    if(root->data>=low&&root->data<=high){
        result.push_back(root->data);
    }
    solve(root->right,low,high,result);
    return;
}
vector<int> printNearNodes(Node *root, int low, int high) {
    vector<int>result;
    solve(root,low,high,result);
    return result;
}
