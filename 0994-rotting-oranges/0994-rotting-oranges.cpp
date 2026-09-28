class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int maxTime=0;
        int m=grid.size();
        int n=grid[0].size();
        int rows[4]={-1,0,1,0};
        int cols[4]={0,-1,0,1};
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxTime=max(maxTime,time);
            for(int i=0;i<4;i++){
                int drow=r+rows[i];
                int dcol=c+cols[i];
                if(drow>=0 && drow<m && dcol>=0 && dcol<n && grid[drow][dcol]==1 && vis[drow][dcol]!=2){
                    q.push({{drow,dcol},time+1});
                    vis[drow][dcol]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};