/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findelem(TreeNode* root,int &k,int &result){
        if(root==NULL) return;
        if(k==0){
            result=root->val;
            return;
        }
        findelem(root->left,k,result);
        k--;
        if(k==0){
            result=root->val;
            return;
        }
        findelem(root->right,k,result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int result=0;
        findelem(root,k,result);
        return result;
    }
};
