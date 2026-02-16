class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,bool>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i==k});
        }
        
        int time=0;
        while(!q.empty()){
            auto[t,isK]=q.front();
            q.pop();
            t--;
            time++;
            if(t==0 && isK){
                return time;
            }
            if(t>0){
                q.push({t,isK});
            }
            
        }
        return time;
        
    }
};