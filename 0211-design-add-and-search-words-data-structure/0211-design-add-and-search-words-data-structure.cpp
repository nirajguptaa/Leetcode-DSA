struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool dfs(string &word,Node *node,int ind){
        if(ind==word.size())return node->isEnd();
        char ch=word[ind];
        if(ch!='.'){
            if(!node->containsKey(ch))return false;
            return dfs(word,node->get(ch),ind+1);
        }
        for(int i=0;i<26;i++){
            if(node->links[i]!=NULL){
                if(dfs(word,node->links[i],ind+1)){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(word,root,0);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */