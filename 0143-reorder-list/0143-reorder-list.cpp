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
    ListNode* reverse(ListNode *node){
        ListNode *curr=node;
        ListNode *prev=NULL;
        while(curr){
            ListNode *ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *secondHalf=slow->next;
        slow->next=NULL;
        ListNode *rev=reverse(secondHalf);
        //merging
        ListNode *first=head;
        ListNode *second=rev;
        while(second){
            ListNode *next1=first->next;
            ListNode *next2=second->next;
            first->next=second;
            second->next=next1;
            first=next1;
            second=next2;
        }
    }
};
