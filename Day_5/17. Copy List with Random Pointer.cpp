/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* res=head;
        while(head){
            Node* temp=head->next;
            head->next= new Node(head->val);
            head->next->next=temp;
            head=temp;
        }
        Node* ans=res;
        while(res){
            Node* temp=res->next;
            if(res->random==NULL){
                temp->random=NULL;
            }else{
                temp->random=res->random->next;
            }
            res=temp->next;
        }
        res=ans;
        ans=res->next;
        while(res->next){
            Node* temp=res->next;
            res->next=res->next->next;
            res=temp;
        }
        return ans;
    }
};
