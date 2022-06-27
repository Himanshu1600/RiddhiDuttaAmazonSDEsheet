void correctBST( struct Node* root )
{
    Node*first=NULL;
    Node*second=NULL;
    Node*prevnode=NULL;
    while(root!=NULL){
        if(root->left){
            Node* temp=root->left;
            while(temp->right!=NULL && temp->right!=root){
                temp=temp->right;
            }
            if(temp->right!=NULL){
                if(prevnode!=NULL && prevnode->data>root->data){
                    if(first==NULL) first=prevnode;
                    second=root;
                }
                prevnode=root;
                temp->right=NULL;
                root=root->right;
            }else{
                temp->right=root;
                root=root->left;
            }
        }else{
            if(prevnode!=NULL && prevnode->data>root->data){
                if(first==NULL) first=prevnode;
                second=root;
            }
            prevnode=root;
            root=root->right;
        }
    }
    if(first!=NULL && second!=NULL){
        swap(first->data,second->data);
    }
    return;
}
