class Solution {
public:
    long long calSum(int r,int c,vector<vector<int>>& grid, int k,vector<vector<int>>&vis){
        int m=grid.size();
        int n=grid[0].size();
        long long sum=grid[r][c];
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]!=0 && vis[nrow][ncol]==0){
                sum+=calSum(nrow,ncol,grid,k,vis);
            }
        }
        return sum;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long sum=calSum(i,j,grid,k,vis);
                    if(sum%k==0){
                        ans+=1;
                    }

                }
            }
        }
        return ans;
    }
};