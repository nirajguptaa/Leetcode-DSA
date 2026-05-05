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
        if(head==NULL|| k==0)return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0)return head;
        tail->next=head;

        int count=len-k;
        ListNode *temp=head;
        while(--count>0){
            
            temp=temp->next;
            
        }
        ListNode *newHead=temp->next;
            
        temp->next=NULL;
        return newHead;
        
    }

};