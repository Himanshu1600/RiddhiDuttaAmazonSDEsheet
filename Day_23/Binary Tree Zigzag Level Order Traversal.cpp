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
    void solve(TreeNode* root,int level,map<int,vector<int>>&mp){
        if(root==NULL) return;
        mp[level].push_back(root->val);
        solve(root->left,level+1,mp);
        solve(root->right,level+1,mp);
        return;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        map<int,vector<int>>mp;
        solve(root,0,mp);
        bool flag = false;
        for(auto it:mp){
            if(flag){
                reverse(it.second.begin(),it.second.end());
                result.push_back(it.second);
                flag=false;
            }else{
                result.push_back(it.second);
                flag=true;
            }
        }
        return result;
    }
};
