class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<int>ans;
        vector<int> adj[numCourses];
        for (auto p : prerequisites) {
            int u = p[0];
            int v = p[1];
            indegree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    ans.push_back(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return ans.size()==numCourses?ans:vector<int>{};
    }
};