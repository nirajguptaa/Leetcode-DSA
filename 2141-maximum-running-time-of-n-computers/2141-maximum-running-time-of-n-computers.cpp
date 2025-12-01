class Solution {
public:
    bool f(int n,vector<int>& batteries,long long T){
        long long usable=0;
        for(long long b:batteries){
            usable+=min(b,T);
        }
        return usable>=n*T;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=0;
        long long sum=accumulate(batteries.begin(),batteries.end(),0LL);
        long long h=sum/n;
        long long ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(f(n,batteries,mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};