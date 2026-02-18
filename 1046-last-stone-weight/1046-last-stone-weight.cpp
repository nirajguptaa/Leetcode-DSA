class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int ele1=pq.top();
            pq.pop();
            int ele2=pq.top();
            pq.pop();
            int diff=abs(ele1-ele2);
            pq.push(diff);
        }
        return pq.top();
        
    }
};