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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *node=head;
        while(node){
            node=node->next;
            len++;
        }
        if(n==len)return head->next;
        int remove=len-n;
        node=head;
        while(remove>1){
            node=node->next;
            remove--;
        }
       
        node->next=node->next->next;
        return head;
    }
};