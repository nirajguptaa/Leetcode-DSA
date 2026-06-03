class Solution {
public:
    long long solve(vector<int>&Astart,vector<int>&Adur,vector<int>&Bstart,vector<int>&Bdur){
        int n=Astart.size();
        long long earliestFinish=INT_MAX;
        for(int i=0;i<n;i++){
            earliestFinish=min((int)earliestFinish,Astart[i]+Adur[i]);
        }
        long long minTime=INT_MAX;

        for(int i=0;i<Bstart.size();i++){
            long long endTime=max((int)earliestFinish,Bstart[i]);
            long long finish=endTime+Bdur[i];
            minTime=min(minTime,finish);
        }
        return minTime;

    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long ans=LLONG_MAX;
        ans=min(ans,solve(landStartTime,landDuration,waterStartTime,waterDuration));
        ans=min(ans,solve(waterStartTime,waterDuration,landStartTime,landDuration));
        return (int)ans;
    }
};