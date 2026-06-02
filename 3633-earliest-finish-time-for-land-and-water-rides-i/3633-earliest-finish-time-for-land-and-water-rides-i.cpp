class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        
        for(int i=0;i<landStartTime.size();i++){
            int landStart=landStartTime[i];
            int lastEnd=landStartTime[i]+landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                int waterStart=max(lastEnd,waterStartTime[j]);
                int waterEnd=waterStart+waterDuration[j];
                ans=min(ans,waterEnd);
                
            }
            
        }
        for(int i=0;i<waterStartTime.size();i++){
            int waterStart=waterStartTime[i];
            int waterEnd=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                int landStart=max(waterEnd,landStartTime[j]);
                int landEnd=landStart+landDuration[j];
                ans=min(ans,landEnd);
                
            }
            
        }
        return ans;
    }
};