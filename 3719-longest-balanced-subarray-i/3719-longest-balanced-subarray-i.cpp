class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>seenEven,seenOdd;
            int evencount=0,oddcount=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0){
                    if(!seenEven.count(nums[j])){
                        seenEven.insert(nums[j]);
                        evencount++;
                    }
                }else{
                    if(!seenOdd.count(nums[j])){
                        seenOdd.insert(nums[j]);
                        oddcount++;
                    }
                }
                if(evencount==oddcount){
                    ans=max(ans,j-i+1);
                }
            }
            
        }
        
        return ans;
    }
};