class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        long long  sum=0;
        for(auto &row:grid){
            for(int x:row){
                sum+=x;
            }
        }
        if(sum%2!=0)return false;
        long long target=sum/2;
        //horizontal check
        long long curr=0;
        for(int i=0;i<r-1;i++){
            long long rowSum=0;
            for(int j=0;j<c;j++){
                rowSum+=grid[i][j];
            }
            curr+=rowSum;
            if(curr==target)return true;

        }

        //vertical check
        curr=0;
        for(int j=0;j<c-1;j++){
            long long colSum=0;
            for(int i=0;i<r;i++){
                colSum+=grid[i][j];
            }
            curr+=colSum;
            if(curr==target)return true;
        }
        return false;
    }
};