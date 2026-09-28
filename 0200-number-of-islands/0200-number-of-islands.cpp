class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        grid[row][col]='0';
        int rows[4]={0,-1,0,1};
        int cols[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int drow=row+rows[i];
            int dcol=col+cols[i];
            if(drow>=0 && drow<m && dcol>=0 && dcol<n && grid[drow][dcol]=='1'){
                dfs(drow,dcol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
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