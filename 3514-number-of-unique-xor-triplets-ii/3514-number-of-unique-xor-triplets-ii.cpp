class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> vals(st.begin(), st.end());
        vector<bool>pairXOR(2048,false);
        for(int a:vals){
            for(int b:vals){
                pairXOR[a^b]=true;
            }
        }
        vector<bool>ans(2048,false);
        for(int i=0;i<2048;i++){
            if(!pairXOR[i]){
                continue;
            }
            for(int x:vals){
                ans[i^x]=true;
            }
        }
        return count(ans.begin(),ans.end(),true);
    }
};