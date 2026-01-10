class Solution {
public:
    bool check(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            unordered_map<char,int>freq;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){

                    freq[board[i][j]]++;
                }
                if(freq[board[i][j]]>1){
                    return false;
                }
                
            }
        }
        for(int j=0;j<9;j++){
            unordered_map<char,int>freq;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){

                    freq[board[i][j]]++;
                }
                if(freq[board[i][j]]>1){
                    return false;
                }
                
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_map<char,int>freq;
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        char val = board[i + x][j + y];
                        if(val!='.'){
                            freq[val]++;
                            if(freq[val]>1){
                                return false;
                            }
                        }
                    }
                }
                

            }
        }
        
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return check(board);
    }
};