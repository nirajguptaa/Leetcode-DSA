class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        while(k>1){
            auto node=pq.top();
       
            pq.pop();
            int row=node.second.first;
            int col=node.second.second;
            if(col+1<matrix[0].size()){
                pq.push({matrix[row][col+1],{row,col+1}});

            }
            k--;
        }
        return pq.top().first;
    }
};