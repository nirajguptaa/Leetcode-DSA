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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return 0;
        ListNode *curr=head;
        ListNode *node=new ListNode(-1);
        ListNode *follow=node;
        while(curr){
            if(curr->val!=val){
                node->next=new ListNode(curr->val);
                node=node->next;
            }
            curr=curr->next;
            
        }
        return follow->next;
        
    }
};