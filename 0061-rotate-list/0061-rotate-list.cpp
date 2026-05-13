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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(head==NULL)return NULL;
        if(k==0)return head;
        ListNode *t=head;
        while(t){
            len++;
            t=t->next;
        }
        
        k%=len;
        if(k==0)return head;
        int remain=len-k;
        t=head;
        while(remain>1){
            t=t->next;
            remain--;
        }
        ListNode *ahead=t->next;
        ListNode *curr=ahead;
        t->next=NULL;
        while(ahead->next!=NULL){
            ahead=ahead->next;
        }
        ahead->next=head;
        return curr;
    }
};