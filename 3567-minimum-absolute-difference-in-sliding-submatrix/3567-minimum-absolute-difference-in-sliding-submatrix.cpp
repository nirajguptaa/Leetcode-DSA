class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int r=m-k+1,c=n-k+1;
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                vector<int>temp;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        temp.push_back(grid[x][y]);
                    }
                }
                sort(temp.begin(),temp.end());
                int mini=INT_MAX;
                for(int x=1;x<temp.size();x++){
                    if(temp[x]!=temp[x-1]){

                        mini=min(mini,abs(temp[x]-temp[x-1]));
                    }
                }
                ans[i][j]=(mini==INT_MAX?0:mini);
            }
        }
        return ans;
    }
};