class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int h=height.size()-1;
        int water=0;
        while(l<h){
            int width=h-l;
            int minn=min(height[l],height[h]);
            water=max(water,minn*width);
            if(height[l]<height[h]){
                l++;
            }else{
                h--;
            }
        }
        return water;
        
    }
};