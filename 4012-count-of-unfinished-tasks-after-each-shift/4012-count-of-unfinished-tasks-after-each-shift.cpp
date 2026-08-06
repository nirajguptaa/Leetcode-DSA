class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long>prefix(n);
        prefix[0]=tasks[0];
        for(int i=1;i<tasks.size();i++){
            prefix[i]=prefix[i-1]+tasks[i];
        }
        vector<int>ans;
        long long total=prefix.back();
        long long comp=0;
        for(int i=0;i<shifts.size();i++){
            comp+=shifts[i];
            if(comp>=total){
                ans.push_back(0);
                comp=0;
                continue;
            }
            int idx=upper_bound(prefix.begin(),prefix.end(),comp)-prefix.begin();
            ans.push_back(n-idx);

        }
        return ans;
    }
};