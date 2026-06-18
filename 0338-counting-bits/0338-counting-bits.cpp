class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        
        for(int i=1;i<n+1;i++){
            ans[i]=ans[i>>1]+(i&1);
        }
        return ans;
    }
};
//Number of set bits in i = Number of set bits in (i/2) + Last bit of i