class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len=original.size();
        vector<vector<int>>mat(m,vector<int>(n));
        if(original.size() != m * n)

            return {};
        
        for(int i=0;i<len;i++){
            mat[i/n][i%n]=original[i];
        }
        return mat;
    }
};