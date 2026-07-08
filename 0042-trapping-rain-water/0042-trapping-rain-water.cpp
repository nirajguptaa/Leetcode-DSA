class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int water=0;
        int lmax=height[l],rmax=height[r];
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(lmax,height[l]);
                int diff=lmax-height[l];
                water+=max(0,diff);
            }else{
                r--;
                rmax=max(rmax,height[r]);
                int diff=rmax-height[r];
                water+=max(0,diff);
            }
        }
        return water;
    }
};