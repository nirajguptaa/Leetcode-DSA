class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int>r1,r2;
        for(int x:nums){
            if(x%3==1)r1.push_back(x);
            else if(x%3==2)r2.push_back(x);
        }
        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());
        if(sum%3==0)return sum;
        int rem=sum%3;
        int removeVal=INT_MAX;
        if(rem==1){
            if(!r1.empty()){
                removeVal=min(removeVal,r1[0]);
            }
            if(r2.size()>=2){
                removeVal=min(removeVal,r2[0]+r2[1]);
            }
        }
        if(rem==2){
            if(!r2.empty()){
                removeVal=min(removeVal,r2[0]);
            }
            if(r1.size()>=2){
                removeVal=min(removeVal,r1[0]+r1[1]);
            }
        }
        if(removeVal==INT_MAX){
            return 0;
        }
        return sum-removeVal;

    }
};