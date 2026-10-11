class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n=nums1.size();
        vector<int>countDiff(10e5+1,0);
        for(int i=0;i<n;i++){
            int diff=abs(nums1[i]-nums2[i]);
            countDiff[diff]++;
        }
        
        int k=k1+k2;
        for(int currDiff=10e5;currDiff>0 && k>0;currDiff--){
            int countOps=min(k,countDiff[currDiff]);
            countDiff[currDiff]-=countOps;
            countDiff[currDiff-1]+=countOps;
            k-=countOps;
        }
        long long res=0;
        for(long long d=1;d<=10e5;d++){
            res+=(countDiff[d]*d*d);
        }

        return res;

    }
};