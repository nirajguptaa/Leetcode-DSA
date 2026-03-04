class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<int>rows(r,0);
        vector<int>cols(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    rows[i]+=1;
                    cols[j]+=1;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1 && rows[i]==1 && cols[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};