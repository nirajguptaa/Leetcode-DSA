class Solution {
public:
    bool safe(int row,int col,char val,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==val){
                return false;
            }
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==val){
                return false;
            }
        }
        int sR=row-row%3;
        int sC=col-col%3;
        for(int i=sR;i<sR+3;i++){
            for(int j=sC;j<sC+3;j++){
                if(board[i][j]==val){
                    return false;
                }
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(safe(i,j,k,board)){
                            board[i][j]=k;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};