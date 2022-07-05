void rightviewoftree(Node*root,vector<int>&result,int level){
    if(root==NULL){
        return;
    }
    if(level==result.size()){
        result.push_back(root->data);
    }
    rightviewoftree(root->right,result,level+1);
    rightviewoftree(root->left,result,level+1);
}
//Function to return list containing elements of right view of binary tree.
vector<int> rightView(Node *root)
{
   vector<int>result;
   rightviewoftree(root,result,0);
   return result;
}
