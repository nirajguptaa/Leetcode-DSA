class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        double ab=(double)a/b;
        int count=0;
        for(int i=0;i<nums.size();i++){
            int x=0,y=0;
            int j=i;
            while(j<nums.size()){
                if(nums[j]%2==0){
                    x++;
                }else{
                    y++;
                }
                if(y>0){

                    double xy=(double)x/y;
                    if(xy<=ab){
                        count++;
                    }
                }
                j++;
            } 
        }
        return count;
    }
};