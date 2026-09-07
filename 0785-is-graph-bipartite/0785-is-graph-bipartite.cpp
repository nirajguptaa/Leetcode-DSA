class Solution {
public:
    bool dfs(int idx,int col,vector<int>&color,vector<vector<int>>& graph){
        color[idx]=col;
        for(int i=0;i<graph[idx].size();i++){
            int neigh=graph[idx][i];
            if(color[neigh]==col){
                return false;
            }
            else if(color[neigh]==-1){
                if(dfs(neigh,!col,color,graph)==false){
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
                if(dfs(i,0,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};