/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node *curr=head;
        while(curr){
            Node *copied=new Node(curr->val);
            copied->next=curr->next;
            curr->next=copied;
            curr=copied->next;
        }
        curr=head;
        //assign random pointers
        while(curr){
            Node *copied=curr->next;
            if(curr->random){

                copied->random=curr->random->next;
            }
            curr=copied->next;
        }
        Node *dummy=new Node(-1);
        Node *copytail=dummy;
        curr=head;
        while(curr){
            Node *copied=curr->next;
            copytail->next=copied;
            copytail=copytail->next;
            curr->next=copied->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};