class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.first-a.second<b.first-b.second;
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        int count=0;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({capacity[i],rocks[i]});
        }
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<n;i++){
            if(additionalRocks>0){
                int cap=p[i].first;
                int rocks=p[i].second;
                int req=cap-rocks;
                int RocksReq=min(req,additionalRocks);
                p[i].second+=RocksReq;
                additionalRocks-=RocksReq;
            }
        }
        for(int i=0;i<n;i++){
            if(p[i].first==p[i].second){
                count++;
            }
        }
        return count;
    }
};