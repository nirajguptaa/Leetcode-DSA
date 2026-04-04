class Solution {
public:
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int drow[4]={-1, 0, 1, 0};
            int dcol[4]={0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && vis[nr][nc]!=1 ){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }

        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};