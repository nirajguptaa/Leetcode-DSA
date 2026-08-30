class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minEle=nums[0],maxEle=nums[0];
        int minIdx=0,maxIdx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>maxEle){
                maxEle=nums[i];
                maxIdx=i;
            }
            if(nums[i]<minEle){
                minEle=nums[i];
                minIdx=i;
            }
        }
        int bothFront=max(minIdx,maxIdx)+1;
        int bothEnd=n-min(minIdx,maxIdx);
        int minFrontmaxBack=minIdx+1+n-maxIdx;
        int maxFrontminBack=maxIdx+1+n-minIdx;
        return min({bothFront,bothEnd,minFrontmaxBack,maxFrontminBack});

    }
};