class Solution {
public:
    void dfs(int node,vector<vector<int>>&ans,unordered_map<int,vector<int>>&adj){
        while(!adj[node].empty()){

            int next=adj[node].back();
            adj[node].pop_back();
            dfs(next,ans,adj);
            ans.push_back({node,next});
        }
        
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>outdegree;
        unordered_map<int,int>indegree;
        for(auto &it:pairs){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int start=pairs[0][0];
        for(auto &it:outdegree){
            int  node=it.first;
            if(outdegree[node]==indegree[node]+1){
                start=node;
                break;
            }
        }
        vector<vector<int>>ans;
        dfs(start,ans,adj);
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};