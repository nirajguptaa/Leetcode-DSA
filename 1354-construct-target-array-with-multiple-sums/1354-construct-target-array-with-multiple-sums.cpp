class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long >pq;
        long long sum=0;
        for(auto t:target){
            pq.push(t);
            sum+=t;
        }
        
        while(!pq.empty()){

            long long top=pq.top();
            pq.pop();
            long long rest=sum-top;
            if(top==1)return true;
            if(rest==1)return true;
            if(rest==0 || rest>=top)return false;
            long long prev=top%rest;
            if(prev==0)return false;
            pq.push(prev);
            sum=rest+prev;
        }
        return true;
    }
};