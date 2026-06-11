class Solution {
public:
    int maxDepth=0;
    const int MOD=1e9+7;
    void dfs(int node,vector<int>adj[],int par,int depth){
        maxDepth=max(maxDepth,depth);
        for(auto neigh:adj[node]){
            if(neigh==par)continue;
            dfs(neigh,adj,node,depth+1);
        }
        
    }
    long long modPow(long long base,long long exp){
        long long ans=1;
        while(exp>0){
            if(exp & 1){
                ans=(ans*base)%MOD;
            }
            base=(base*base)%MOD;
            exp>>=1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int>adj[n+1];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        
        dfs(1,adj,-1,0);
        
        return modPow(2, maxDepth - 1);
    }
};