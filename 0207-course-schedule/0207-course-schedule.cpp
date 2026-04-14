class Solution {
public:
    bool dfs(int idx,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>&adj){
        vis[idx]=1;
        pathVis[idx]=1;
        for(auto it:adj[idx]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj))return true;
            }else if(pathVis[it]==true){
                return true;
            }
        }
        pathVis[idx]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto p:prerequisites){
            int u=p[0];
            int v=p[1];
            adj[v].push_back(u);
        }
        //cycle detection
        vector<int>vis(numCourses,0);
        vector<int>pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj))return false;
            }
        }
        return true;

    }
};