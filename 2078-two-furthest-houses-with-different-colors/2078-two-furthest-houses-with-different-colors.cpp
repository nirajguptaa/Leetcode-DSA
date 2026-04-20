class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dist=0;
        int n=colors.size();
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]!=colors[n-1]){
                dist=max(dist,n-i-1);
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(colors[i]!=colors[0]){
                dist=max(dist,i);
                break;
            }
        }
        return dist;
    }
};