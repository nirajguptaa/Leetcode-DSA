class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&pathVis, vector<int>adj[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }

        }
        pathVis[node]=0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto p:prerequisites){
            int u=p[0];
            int v=p[1];//v->u
            adj[v].push_back(u);
            
        }
        vector<int>pathVis(numCourses);
        vector<int>vis(numCourses);
        
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return false;
                }
            }
        }
        return true;

    }
};