class Solution {
public:
    void  dfs(int node,vector<int>&vis,vector<int>adj[],int &vertices,int &degreeSum){
        vis[node]=1;
        vertices++;
        degreeSum+=adj[node].size();
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,vertices,degreeSum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int count=0;
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int vertices=0;
                int degreeSum=0;
                dfs(i,vis,adj,vertices,degreeSum);
                int actualEdge=degreeSum/2;
                int reqEdge=vertices*(vertices-1)/2;
                count+=actualEdge==reqEdge;
            }
        }
        return count;
    }
};