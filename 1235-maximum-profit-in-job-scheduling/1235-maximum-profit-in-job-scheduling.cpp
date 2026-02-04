class Solution {
public:
    vector<int>dp;
    vector<vector<int>>jobs;
    int n;
    int f(int ind){
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int skip=f(ind+1);
        int lo=ind+1,h=n-1,nextInd=n;
        while(lo<=h){
            int mid=(lo+h)/2;
            if(jobs[mid][0]>=jobs[ind][1]){
                nextInd=mid;
                h=mid-1;
            }else{
                lo=mid+1;
            }
        }
        int take=jobs[ind][2]+f(nextInd);
        return dp[ind]=max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        jobs.resize(n);
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        dp.assign(n,-1);
        return f(0);
        
    }
};
//f(i) = maximum profit you can get starting from job index i to the end