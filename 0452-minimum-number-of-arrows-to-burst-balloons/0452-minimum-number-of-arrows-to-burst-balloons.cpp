class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++){
            int currStart=points[i][0];
            
            if(currStart<=end){
                end=min(end,points[i][1]);
            }else{
                
                count+=1;
                end=points[i][1];
            }
        }
        return count;
    }
};