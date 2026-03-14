class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        // for(int i=0;i<n+1;i++){
        //     ans[i]=__builtin_popcount(i);//O(n log n)
        //     //For each number i, the number of bits is about:log₂(i)
        // }
        for(int i=1;i<n+1;i++){
            ans[i]=ans[i>>1]+(i&1);
        }
        return ans;
    }
};