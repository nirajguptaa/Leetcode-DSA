class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        for(int s:stones){
            if(s%3==1){
                cnt1++;
            }else if(s%3==2){
                cnt2++;
            }else if(s%3==0){
                cnt0++;
            }

        }
        if(cnt0%2==0){
            return cnt1>0 && cnt2>0;
        }
        
        return abs(cnt1-cnt2)>2;
            
        
        
    }
};