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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        int carry=0;
        ListNode *node=new ListNode(NULL);
        ListNode *dummy=node;
        int sum=0;
        while(p1 && p2){
            sum+=carry;
            sum+=p1->val;
            sum+=p2->val;
            p1=p1->next;
            p2=p2->next;
            int r=sum%10;
            carry=sum/10;
            node->next=new ListNode(r);
            node=node->next;
            sum=0;
        }
        while(p1){
            sum+=carry;
            sum+=p1->val;
            p1=p1->next;
            int r=sum%10;
            carry=sum/10;
            node->next=new ListNode(r);
            node=node->next;
            sum=0;
        }
        while(p2){
            sum+=carry;
            sum+=p2->val;
            p2=p2->next;
            int r=sum%10;
            carry=sum/10;
            node->next=new ListNode(r);
            node=node->next;
            sum=0;
        }
        if(carry!=0){
            node->next=new ListNode(carry);
        }
        return dummy->next;
    }
};