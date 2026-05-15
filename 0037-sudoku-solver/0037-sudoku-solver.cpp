class Solution {
public:
    bool safe(char num,int row,int col,vector<vector<char>>& board){
        for(int j=0;j<9;j++){
            if(board[j][col]==num){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==num){
                return false;
            }
                
        }
        int startRow=row-row%3;
        int startCol=col-col%3;
        for(int i=startRow;i<startRow+3;i++){
            for(int j=startCol;j<startCol+3;j++){
                if(board[i][j]==num){
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
                    for(char num='1';num<='9';num++){
                        if(safe(num,i,j,board)){
                            board[i][j]=num;
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