class Solution {
public:
    void dfs(int k,vector<bool>&sus,vector<int>adj[]){
        sus[k]=true;
        for(auto neigh:adj[k]){
            if(!sus[neigh]){
                dfs(neigh,sus,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<bool>sus(n,false);
        dfs(k,sus,adj);
        for(auto &it:invocations){
            int u=it[0];
            int v=it[1];
            if(!sus[u] && sus[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};