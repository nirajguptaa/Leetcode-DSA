class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long firstHalf=0;
        for(int i=0;i<n/2;i++){
            firstHalf+=nums[i];
        }
        long long secondHalf=sum-firstHalf;
        long long r=n/2;
        int count=0;
        for(long long l=0;l<n;l++){
            if(firstHalf>secondHalf){
                count++;
            }
            firstHalf+=nums[r];
            firstHalf-=nums[l];
            secondHalf+=nums[l];
            secondHalf-=nums[r];

            r=(r+1)%n;
        }
        return count;
    }
};