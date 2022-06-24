class Solution {
public:
    int finddiameter(TreeNode* root,int &result){
        if(root==NULL) return 0;
        int left=finddiameter(root->left,result);
        int right=finddiameter(root->right,result);
        result=max(result,left+right);
        return 1+max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int result=0;
        finddiameter(root,result);
        return result;
    }
};
