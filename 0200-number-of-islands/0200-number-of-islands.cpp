class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid){
        grid[row][col]='0';
        int drow[4]={-1,1,0,0};
        int dcol[4]={0,0,-1,1};
        for( int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1'){
                dfs(nr,nc,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};