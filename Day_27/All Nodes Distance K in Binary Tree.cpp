/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* tar,TreeNode* prev,int k,unordered_map<TreeNode*,TreeNode*>mp,vector<int>&result){
        if(tar==NULL) return;
        if(k==0){
            result.push_back(tar->val);
            return;
        }
        
        if(prev!=mp[tar]){
            dfs(mp[tar],tar,k-1,mp,result);
        }
        if(tar->left!=prev){
            dfs(tar->left,tar,k-1,mp,result);
        }
        if(tar->right!=prev){
            dfs(tar->right,tar,k-1,mp,result);
        }
        return;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>mp;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->left){
                mp[it->left]=it;
                q.push(it->left);
            }
            if(it->right){
                mp[it->right]=it;
                q.push(it->right);
            }
        }
        vector<int>result;
        //TreeNode* prev=NULL;
        dfs(target,NULL,k,mp,result);
        return result;
    }
};
