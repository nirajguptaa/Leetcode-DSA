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
    ListNode* reverseList(ListNode* head) {
        ListNode *node=head;
        ListNode *prev=NULL;
        ListNode *ahead=node;
        while(node  && ahead){
            ahead=node->next;
            node->next=prev;
            prev=node;
            node=ahead;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *l2=reverseList(slow->next);
        slow->next=NULL;
        ListNode *l1=head;
        
        while(l1 && l2){
            ListNode *temp1=l1->next;
            ListNode *temp2=l2->next;
            l1->next=l2;
            l2->next=temp1;
            l1=temp1;
            l2=temp2;
        }
        
        

            
    }
};