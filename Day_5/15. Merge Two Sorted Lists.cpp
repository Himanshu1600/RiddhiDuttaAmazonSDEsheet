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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* res;
        ListNode* ans;
        if(list1->val<list2->val){
            res=list1;
            list1=list1->next;
        }else{
            res=list2;
            list2=list2->next;
        }
        ans=res;
        while(list1 && list2){
            if(list1->val<list2->val){
                res->next=list1;
                res=res->next;
                list1=list1->next;
            }else if(list2->val<list1->val){
                res->next=list2;
                list2=list2->next;
                res=res->next;
            }else{
                res->next=list1;
                list1=list1->next;
                res=res->next;
                res->next=list2;
                list2=list2->next;
                res=res->next;
            }
        }
        if(list1==NULL){
            res->next=list2;
        }else{
            res->next=list1;
        }
        return ans;
    }
};
