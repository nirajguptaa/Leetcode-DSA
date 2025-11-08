class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int drow[4]={-1, 0, 1, 0};
            int dcol[4]={0, 1, 0, -1};
            for(int x=0;x<4;x++){
                int r=row+drow[x];
                int c=col+dcol[x];
                if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0 && grid[r][c]=='1'){
                    vis[r][c]=1;
                    q.push({r,c});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};