class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGcd(n);
        
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int currGcd=gcd(nums[i],maxi);
            prefixGcd[i]=currGcd;
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        int l=0,r=n-1;
        while(l<r){
            ans+=gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;

    }
};