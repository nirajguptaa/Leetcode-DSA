struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    bool flag=false;
    void setFlag(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Solution {
public:
    Node *root;
    Solution(){
        root=new Node();
    }
    void insert(string word){
        Node *node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setFlag();
    }
    void dfs(int row,int col,vector<vector<char>>& board,string &path,Node *node,vector<string>&ans){
        char ch=board[row][col];
        if(ch=='#' || !node->containsKey(ch)){
            return ;
        }
        node=node->get(ch);
        path.push_back(ch);
        if(node->isEnd()){
            ans.push_back(path);
            node->flag=false;
        }
        board[row][col]='#';
        int drow[4]={1,-1,0,0};
        int dcol[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=row+drow[i];
            int nc=col+dcol[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size()){
                dfs(nr,nc,board,path,node,ans);
            }
        }   
        board[row][col]=ch;
        path.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words){
            insert(word);
        }
        vector<string>ans;
        string path="";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i,j,board,path,root,ans);
            }
        }
        return ans;

    }
};