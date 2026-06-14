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
    ListNode *reverse(ListNode *node){
        if(node==NULL || node->next==NULL){
            return node;
        }
        ListNode *prev=NULL;
        ListNode *curr=node;
        while(curr){
            ListNode *ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *secondHalf=reverse(slow);
        int maxTwin=0;
        ListNode *first=head,*second=secondHalf;
        
        while(first && second){
            int value=first->val+second->val;
            maxTwin=max(maxTwin,value);
            first=first->next;
            second=second->next;
        }
        return maxTwin;
        
    }
};