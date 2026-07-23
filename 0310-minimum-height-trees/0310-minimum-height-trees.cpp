class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        int remain=n;
        
        while(remain>2){
            int sz=q.size();
            remain-=sz;
            while(sz--){
                auto node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    indegree[it]--;
                    if(indegree[it]==1){
                        q.push(it);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
            
    }
};