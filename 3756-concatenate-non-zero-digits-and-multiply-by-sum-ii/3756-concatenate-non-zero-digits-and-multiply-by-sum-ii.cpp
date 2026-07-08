class Solution {
public:
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        const int mod=1e9+7;
        vector<long long> prefSum(n + 1, 0);
        vector<long long>valueUpTo(n+1,0);
        vector<long long>k(n+1,0);
        vector<long long>pow10(n+1,0);
        pow10[0]=1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }
        for(int i=1;i<=n;i++){
            int d=s[i-1]-'0';
            prefSum[i] = prefSum[i - 1] + d;
            if(d!=0){
                valueUpTo[i]=(valueUpTo[i-1]*10+d)% mod;
                k[i]=k[i-1]+1;
            }else{
                valueUpTo[i]=valueUpTo[i-1];
                k[i]=k[i-1];
            }
        }
        

        vector<int> ans;
        for (auto it : queries) {
            int l = it[0], r = it[1];
            int sum = prefSum[r + 1] - prefSum[l];
            int K=k[r+1]-k[l];
            long long val=(valueUpTo[r+1]-(valueUpTo[l]*pow10[K])%mod+mod)%mod;
            
            ans.push_back((val*sum)%mod);
        }
        return ans;
    }
};