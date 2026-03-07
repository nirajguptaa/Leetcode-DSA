class Solution {
public:
    int dfs(vector<vector<int>>&adj,int seats,int node,int parent){
        int pass=1;
        for(auto child:adj[node]){
            if(child!=parent){
                int p=dfs(adj,seats,child,node);
                pass+=p;
                fuel+=(p+seats-1)/seats;
            }
        }
        return pass;
    }
    long long fuel=0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>>adj(n);
        for(auto &r:roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        dfs(adj,seats,0,-1);
        return fuel;
    }
};