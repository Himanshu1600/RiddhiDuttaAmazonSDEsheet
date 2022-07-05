void leftviewtree(Node* root,vector<int>&ans,int level){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    leftviewtree(root->left,ans,level+1);
    leftviewtree(root->right,ans,level+1);
    return;
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int>leftview;
   leftviewtree(root,leftview,0);
   return leftview;
}
