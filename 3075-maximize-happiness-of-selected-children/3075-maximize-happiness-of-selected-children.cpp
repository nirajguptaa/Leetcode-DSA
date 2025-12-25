class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long n=happiness.size();
        sort(happiness.begin(),happiness.end(),greater<int>());
        
        long long  ans=0;
        for(int i=0;i<k;i++){
            long long curr=happiness[i]-i;
            if(curr<=0)break;
            ans+=curr;
        }
        
        return ans;

    }
};