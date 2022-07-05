Node* connect(Node* root) {
    queue<Node*>q;
    Node* result=root;
    if(root==NULL) return NULL;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* node=q.front();
            q.pop();
            if(i==n-1){
                node->next=NULL;
            }else{
                node->next=q.front();
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return result;
}
