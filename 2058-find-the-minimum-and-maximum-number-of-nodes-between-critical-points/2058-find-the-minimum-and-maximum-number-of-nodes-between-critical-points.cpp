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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev=head;
        ListNode *curr=head->next;
        ListNode *next=head->next->next;
        int count=1;
        vector<int>idx;
        while(next){
            if(curr->val >next->val && curr->val>prev->val){
                idx.push_back(count);
            }else if(curr->val <next->val && curr->val<prev->val){
                idx.push_back(count);
            }
            count++;
            prev=prev->next;
            curr=curr->next;
            next=next->next;
        }
        // return idx;
        int minDistance=1e8,maxDistance=-1;
        int n=idx.size();
        if(n<2){
            return {-1,-1};
        }
        maxDistance=idx[n-1]-idx[0];
        for(int i=0;i<n-1;i++){
            minDistance=min(minDistance,idx[i+1]-idx[i]);
        }
        return {minDistance,maxDistance};
    }
};