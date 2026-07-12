class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int n=arr.size();
        int rank=1;
        for(int x:temp){
            if(mp.find(x)==mp.end()){
                mp[x]=rank;
                rank++;
            }
        }
        vector<int>ans;
        for(auto it:arr){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};