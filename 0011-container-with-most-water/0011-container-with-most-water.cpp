class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lmax=height[0],rmax=height[r];
        int water=0;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);

            int height=min(lmax,rmax);
            int dist=r-l;
            water=max(water,dist*height);
            if(lmax<rmax){
                l++;
            }else{
                r--;
            }
        }
        return water;
    }
};