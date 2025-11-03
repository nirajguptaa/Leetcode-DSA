class Solution {
public:
    void bfs(int node,vector<int>&vis,vector<int>adj[]){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it:adj[top]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;

                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans+=1;
                vis[i]=1;
                bfs(i,vis,adj);
            }
        }
        return ans;
    }
};