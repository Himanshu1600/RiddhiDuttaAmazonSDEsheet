/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return;
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int sz=st.size();
        temp=head;
        for(int i=0;i<sz/2;i++){
            auto node=st.top();
            st.pop();
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        temp->next=NULL;
        return;
    }
};
