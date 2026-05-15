class Solution {
public:
    bool safe(int row,int col,int n,vector<string>&board){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            
                if(board[i][j]=='Q'){
                    return false;
                }
            
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
           
                if(board[i][j]=='Q'){
                    return false;
                }
            
        }
        return true;
    }
    void tryToPlace(int row,vector<string>&board,vector<vector<string>>&ans,int n){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int col=0;col<n;col++){
            if(safe(row,col,n,board)){
                board[row][col]='Q';
                tryToPlace(row+1,board,ans,n);
                board[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        tryToPlace(0,board,ans,n);
        
        return ans;
    }
};