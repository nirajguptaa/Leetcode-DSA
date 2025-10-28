class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        auto simulate=[&](int start,int dir){
            vector<int>a=nums;
            int curr=start;
            while(curr>=0 && curr<nums.size()){
                if(a[curr]==0){
                    curr+=dir;
                }else{
                    a[curr]--;
                    dir*=-1;
                    curr+=dir;
                }
            }
            for(int x:a){
                if(x!=0){
                    return false;
                }
            }
            return true;
        };
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(simulate(i,1))ans++;
                if(simulate(i,-1))ans++;

            }
        }
        return ans;
        
    }
};