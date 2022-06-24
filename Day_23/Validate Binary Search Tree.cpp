class Solution {
public:
    bool checkvalid(TreeNode* root,long long mini,long long maxi){
        if(root==NULL) return true;
        if(root->val>mini&&root->val<maxi){
            return checkvalid(root->left,mini,root->val)&&checkvalid(root->right,root->val,maxi);
        }else{
            return false;
        }
    }
    
    
    bool isValidBST(TreeNode* root) {
        long long mini=-1e18;
        long long maxi=1e18;
        return checkvalid(root,mini,maxi);
    }
};
