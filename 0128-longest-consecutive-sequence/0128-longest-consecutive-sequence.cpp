class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int ans=0;
        for(int num:seen){
            if(seen.find(num-1)==seen.end()){
                int len=1;
                int curr=num;

                while(seen.find(curr+1)!=seen.end()){
                    len++;
                    curr++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};