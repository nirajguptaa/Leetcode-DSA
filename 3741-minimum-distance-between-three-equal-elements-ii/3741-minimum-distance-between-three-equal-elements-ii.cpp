class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int x=INT_MAX;
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        
        for(auto &it:mp){
            vector<int>v=it.second;
            if(v.size()<3)continue;
            for(int i=0;i<v.size()-2;i++){
                int dist=2*(v[i+2]-v[i]);
                x=min(x,dist);
            }
        }
        return x==INT_MAX?-1:x;
    }
};