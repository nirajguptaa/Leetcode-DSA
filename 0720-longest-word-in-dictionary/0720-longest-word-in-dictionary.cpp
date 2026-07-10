struct Node{
    Node *links[26];
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
    }
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    bool flag=false;
    void setEnd(){
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
    void insert(vector<string>&words){
        
        for(string w:words){
            Node *node=root;
            for(int i=0;i<w.size();i++){
                if(!node->containsKey(w[i])){
                    node->put(w[i],new Node());
                }
                node=node->get(w[i]);
            }
            node->setEnd();
        }

    }
    bool check(string &word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
            if(node->isEnd()==false){
                return false;
            }
        }
        return true;
    }

    string longestWord(vector<string>& words) {
        insert(words);
        string ans="";
        for(string w:words){
            if(check(w)){
                if(w.size()>ans.size()){
                    ans=w;
                }else if(w.size()==ans.size() && w<ans){
                    ans=w;
                }

            }
        }
        return ans;
        
    }
};