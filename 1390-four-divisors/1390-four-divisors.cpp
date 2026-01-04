class Solution {
public:
    int count(int num){
        int c=1;
        int sum=num;
        for(int i =1;i<=num/2;i++){
            if(num%i==0){
                sum+=i;
                c++;
            }
            if(c>4)return 0;

        }
        return c==4?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int num:nums){
            ans+=count(num);
        }
        return ans;

    }
};