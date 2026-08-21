class Solution {
public:
    int minimumBoxes(int n) {
        long long floorBoxes=0;
        int used=0;
        int layer=1;
        while(used+(layer*(layer+1))/2<=n){
            used+=(layer*(layer+1))/2;
            floorBoxes+=layer;
            layer++;
        }
        int remain=n-used;
        int extra=0;
        while(remain>0){
            extra++;
            remain-=extra;
        }
        return floorBoxes+extra;
            
    }
};