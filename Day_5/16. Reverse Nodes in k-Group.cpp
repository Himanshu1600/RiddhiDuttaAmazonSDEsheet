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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res=head;
        int cnt=0;
        while(head&&cnt<k){
            head=head->next;
            cnt++;
        }
        if(cnt<k){
            return res;
        }else{
            ListNode* prev=res->next;
            res->next=reverseKGroup(head,k);
            cnt--;
            while(cnt--){
                ListNode* temp=prev->next;
                prev->next=res;
                res=prev;
                prev=temp;
            }
            return res;            
        }
    }
};
