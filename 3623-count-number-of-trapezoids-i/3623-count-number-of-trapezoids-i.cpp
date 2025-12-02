class Solution {
public:
    static const long long mod=1e9+7;
    long long comb2(long long n){
        if(n<2)return 0;
        return (n*(n-1)/2)%mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<long long ,long long>freq;
        for(auto &p:points){
            long long y=p[1];
            freq[y]++;
        }
        vector<long long>pairs;
        pairs.reserve(freq.size());

        for(auto &it:freq){
            pairs.push_back(comb2(it.second));
        }
        long long ans=0;
        long long ps=0;
        for(long long x:pairs){
            ans=(ans+(ps*x)%mod)%mod;
            ps=(ps+x)%mod;
        }
        return ans;
    }
};