class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        vector<vector<int>>mat(m,vector<int>(n));
        if(original.size() != m * n)

            return {};
        int x=0,y=0;
        for(int i=0;i<len;i++){
            mat[x][y]=original[i];
            y++;
            if(y==n){
                x++;
                y=0;
            }
        }
        return mat;
    }
};