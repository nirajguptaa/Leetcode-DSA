class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<char>>& grid,int &count){
        
        grid[i][j]='0';
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for(int x=0;x<4;x++){
            int drow=i+row[x];
            int dcol=j+col[x];
            if(drow>=0 && dcol>=0 && drow<m && dcol<n && grid[drow][dcol]=='1'){
                dfs(drow,dcol,m,n,grid,count);
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
                    dfs(i,j,m,n,grid,count);
                }
            }
        }
        return count;
    }
};