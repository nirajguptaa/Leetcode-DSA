class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            double dist=sqrt(x*x+y*y);
            pq.push({dist,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(k--){
            ans.push_back({pq.top().second.first,pq.top().second.second});
           pq.pop();
        }
        return ans;
    }
};
//building heap-nlogn
// removing k elements- nlogn