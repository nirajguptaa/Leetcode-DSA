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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    ListNode* kthNode(ListNode* head, int k) {
        
        while (head && k>1) {
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr=head;
        ListNode *prev=NULL;//remember the tell of previous processed pard
        ListNode *ahead=NULL;
        while(curr){
            ListNode *kth=kthNode(curr,k);
            if(kth==NULL){
                if(prev){

                    prev->next=curr;
                }
                break;
            }
            
            ahead=kth->next;
            kth->next=NULL;
            ListNode *newHead=reverse(curr);
            if(curr==head){
                head=newHead;
            }else{
                prev->next=newHead;
            }
            prev=curr;
            curr=ahead;
        }
        return head;
    }
};