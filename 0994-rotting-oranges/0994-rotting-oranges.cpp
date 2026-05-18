class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int row[4]={0,+1,0,-1};
        int col[4]={-1,0,1,0};
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int maxTime=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxTime=max(time,maxTime);
            for(int i=0;i<4;i++){
                int drow=r+row[i];
                int dcol=c+col[i];
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && grid[drow][dcol]==1 && vis[drow][dcol]!=2){
                    q.push({{drow,dcol},time+1});
                    vis[drow][dcol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return maxTime;
    }
};