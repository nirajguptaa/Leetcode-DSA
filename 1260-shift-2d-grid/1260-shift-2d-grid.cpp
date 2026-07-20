class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=n*m;
        k=k%total;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=i*n+j;
                int newidx=(idx+k)%total;
                int nrow=newidx/n;
                int ncol=newidx%n;
                ans[nrow][ncol]=grid[i][j];
            }
        }
        return ans;
    }
};