class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        vector<int>ans;
        for(int q:queries){
            int val=nums[q];
            vector<int>&indices=mp[val];
            if(indices.size()<=1){
                ans.push_back(-1);
                continue;
            }
            int k=indices.size();
            int pos=lower_bound(indices.begin(),indices.end(),q)-indices.begin();
            int prev=indices[(pos-1+k)%k];
            int next=indices[(pos+1)%k];
            int d1=min(abs(q-prev),n-abs(q-prev));
            int d2=min(abs(q-next),n-abs(q-next));
            int dist=min(d1,d2);
            ans.push_back(dist);

        }
        return ans;
    }
};