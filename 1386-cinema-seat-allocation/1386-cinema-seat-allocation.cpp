 class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int group=2*n;
        unordered_map<int,int>mp;
        for(auto it:reservedSeats){
            int row=it[0];
            int col=it[1];
            mp[row]|=(1<<col);
        }
        for(auto &[row,m]:mp){
            bool left=(m&(1<<2))==0 && (m &(1<<3))==0 && (m &(1<<4))==0 && (m &(1<<5))==0;
               
            bool middle=(m&(1<<4))==0 && (m &(1<<5))==0 && (m &(1<<6))==0 && (m &(1<<7))==0;
                
            bool right=(m&(1<<6))==0 && (m &(1<<7))==0 && (m &(1<<8))==0 && (m &(1<<9))==0;
            if(left && right){
               
            }else if(left || right|| middle){
                group-=1;
            }else{
                group-=2;
            }
                
        }
        return group;
    }
}; 