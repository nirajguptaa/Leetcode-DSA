class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>>& board, string word,int idx){
        int len=word.size();
        if(idx==len)return true;
        int r=board.size();
        int c=board[0].size();
        if(row<0 || col<0 || row>=r || col>=c || board[row][col]!=word[idx]){
            return false;
        }
        char temp=board[row][col];
        board[row][col]='#';
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(dfs(nrow,ncol,board,word,idx+1)){
                return true;
            }
        }
        board[row][col]=temp;   
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};