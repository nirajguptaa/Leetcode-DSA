class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,int>freq,width;
        for(int p:planks){
            freq[p]++;
        }
        int ans=0;
        for(auto it1=freq.begin();it1!=freq.end();it1++){
            int x=it1->first;
            int f1=it1->second;
            ans=max(ans,width[x]+=f1);
            ans=max(ans,width[2*x]+=f1/2);
            auto it2=it1;
            it2++;
            for(;it2!=freq.end();it2++){
                ans=max(ans,width[x+it2->first]+=min(f1,it2->second));
            }
        }
        return ans;
    }
};