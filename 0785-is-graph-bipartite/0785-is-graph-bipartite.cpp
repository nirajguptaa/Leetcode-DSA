class Solution {
public:
    bool bfs(int idx,vector<int>&color,vector<vector<int>>& graph){
        color[idx]=0;
        queue<int>q;
        q.push(idx);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it:graph[top]){
                if(color[it]==-1){
                    color[it]=!color[top];
                    q.push(it);
                }else if(color[it]==color[top]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};