class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses);

        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};