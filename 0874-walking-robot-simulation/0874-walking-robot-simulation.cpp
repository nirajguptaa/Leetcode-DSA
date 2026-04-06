class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto &o:obstacles){
            st.insert({o[0],o[1]});
        }
        int x=0,y=0;
        int dist=0;
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0;
        for(int cmd:commands){
            if(cmd==-1){
                d=(d+1)%4;
            }else if(cmd==-2){
                d=(d+3)%4;
            }else{
                for(int i=0;i<cmd;i++){
                    int nx=x+dir[d].first;
                    int ny=y+dir[d].second;
                    if(st.find({nx,ny})!=st.end()){
                        break;
                    }
                    x=nx;
                    y=ny;
                    dist=max(dist,x*x+y*y);
                }
            }
        }
        return dist;
    }
};