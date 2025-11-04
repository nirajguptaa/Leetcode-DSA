class Solution {
public:
    void dfs(int row,int col ,vector<vector<int>>& image,int initialcol,int color,vector<vector<int>>&ans,int drow[],int dcol[]){

        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initialcol && ans[nrow][ncol]!=color ){
                dfs(nrow,ncol,image,initialcol,color,ans,drow,dcol);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans=image;
        int initialcol=image[sr][sc];
        if(image[sr][sc]==color){
            return ans;
        }
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        dfs(sr,sc,image,initialcol,color,ans,drow,dcol);
        return ans;
    }
};