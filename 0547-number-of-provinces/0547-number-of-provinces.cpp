class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>& isConnected,int n){
        vis[node]=1;
        for(int j=0;j<n;j++){
            if(!vis[j] && isConnected[node][j]==1){
                dfs(j,vis,isConnected,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n);
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=1;
                dfs(i,vis,isConnected,n);
            }
        }
        return ans;
    }
};