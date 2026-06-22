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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode *newHead=head->next;
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr && curr->next){
            ListNode *ahead=curr->next;
            ListNode *nextPair=ahead->next;
            ahead->next=curr;
            curr->next=nextPair;
            if(prev){
                prev->next=ahead;
            }
            prev=curr;
            curr=nextPair;
        }
        return newHead;
    }
};