class Solution {
public:
    bool dfs(int row,int col,vector<vector<int>>& heights,vector<vector<bool>>& vis){
        int n=heights.size(),m=heights[0].size();
        
        vis[row][col]=true;
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m &&heights[nr][nc]>=heights[row][col]&& !vis[nr][nc]){
                if(dfs(nr,nc,heights,vis)){
                    return true;
                }
            }
        }
        return false;
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pacific);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,pacific);
        }
        for(int i=0;i<n;i++){
            dfs(i,m-1,heights,atlantic);
        }
        for(int j=0;j<m;j++){
            dfs(n-1,j,heights,atlantic);
        }
            
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};