class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int initialCol,int color,vector<vector<int>>&ans){
        ans[sr][sc]=color;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==initialCol && ans[nrow][ncol]!=color){
                dfs(image,nrow,ncol,initialCol,color,ans);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initialCol=image[sr][sc];
        if(image[sr][sc]==color){
            return image;
        }
        
        dfs(image,sr,sc,initialCol,color,ans);
        return ans;
    }
};