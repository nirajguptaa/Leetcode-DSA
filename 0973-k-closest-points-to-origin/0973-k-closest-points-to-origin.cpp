class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(auto it:points){
            int x=it[0];
            int y=it[1];
            double dist=sqrt(x*x+y*y);
            pq.push({dist,{x,y}});
        }
        vector<vector<int>>ans;
        while(k--){
            auto top=pq.top();
            pq.pop();
            vector<int>temp;
            temp.push_back(top.second.first);
            temp.push_back(top.second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};