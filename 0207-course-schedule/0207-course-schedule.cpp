class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<int>adj[numCourses];
        for(auto p:prerequisites){
            int u=p[0];
            int v=p[1];//v->u
            adj[v].push_back(u);
            indegree[u]++;
        }
        vector<int>vis(numCourses);
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(!vis[node]){
                vis[node]=1;
            }
            for(auto neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        bool taken=true;
        for(int i=0;i<numCourses;i++){
            if(vis[i]!=1){
                taken=false;
                break;
            }
        }
        return taken;

    }
};