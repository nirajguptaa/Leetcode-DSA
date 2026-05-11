class Solution {
public:
    vector<int>generateRows(int row){
        long long val=1;
        vector<int>rows;
        rows.push_back(val);
        for(int col=1;col<row;col++){
            val*=(row-col);
            val/=col;
            rows.push_back(val);
        }
        return rows;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            vector<int>temp=generateRows(i);
            ans.push_back(temp);
        }
        return ans;
    }
};