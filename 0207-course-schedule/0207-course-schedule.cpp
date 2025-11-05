class Solution {
public:
    //  bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>& adj){
    //     vis[node]=1;
    //     pathvis[node]=1;
    //     for(auto it:adj[node]){
    //         if(!vis[it]){
    //             if(dfs(it,vis,pathvis,adj)){
    //                 return true;
    //             }
    //         }
    //         else if(pathvis[it]){
    //             return true;
    //         }
    //     }
    //     pathvis[node]=0;
    //     return false;
    //  }
            
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        // vector<int>vis(numCourses,0);
        // vector<int>pathvis(numCourses,0);
        // for(int i=0;i<numCourses;i++){
        //     if(!vis[i]){
        //         if(dfs(i,vis,pathvis,adj)){
        //             return false;
        //         }
        //     }
        // }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            count++;
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return count==numCourses;
            
    }
};