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
class node{
    public:
    bool reverse=false;
    stack<TreeNode*>st;
    node(TreeNode* root,bool reversed){
        reverse=reversed;
        pushall(root);
    }
    int next(){
        auto it=st.top();
        st.pop();
        if(reverse){
            pushall(it->left);
        }else{
            pushall(it->right);
        }
        return it->val;
    }
    
    void pushall(TreeNode* root){
        if(root==NULL) return;
        if(reverse){
            while(root!=NULL){
                st.push(root);
                root=root->right;
            }
        }else{
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
        }
    }
};
class Solution {
public:    
    bool findTarget(TreeNode* root, int k) {
        node left(root,false);
        node right(root,true);
        int i=left.next();
        int j=right.next();
        while(i<j){
            if((i+j)==k) return true;
            if((i+j)<k){
                i=left.next();
            }else{
                j=right.next();
            }
        }
        return false;
        
    }
};
