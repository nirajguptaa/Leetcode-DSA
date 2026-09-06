class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid){
        grid[row][col]='0';
        int n=grid.size();
        int m=grid[0].size();
        int rows[4]={-1,1,0,0};
        int cols[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int drow=row+rows[i];
            int dcol=col+cols[i];
            if(drow>=0 && drow< n && dcol>=0 && dcol<m && grid[drow][dcol]=='1'){
                dfs(drow,dcol,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};