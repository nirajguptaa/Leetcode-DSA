class Solution {
public:
    int f(int idx,vector<vector<int>>& jobs,vector<int>&dp){
        int n=jobs.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int next=lower_bound(jobs.begin(),jobs.end(),jobs[idx][1],[](const vector<int>&job,int endTime){
            return job[0]<endTime;
        })-jobs.begin();
        
        int take=jobs[idx][2]+f(next,jobs,dp);
        int notake=f(idx+1,jobs,dp);
        return dp[idx]=max(take,notake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n+1,-1);
        return f(0,jobs,dp);
    }
};

//The comparator tells lower_bound to compare a job’s start time with the current job’s end time.
// It keeps moving right while start < endTime and stops at the first job where start >= endTime, 
//which is the next non-overlapping job.
