class WordFilter {
public:
    unordered_map<string,int>mp;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string word=words[i];
            int n=word.size();
            for(int j=0;j<=n;j++){
                string pref=word.substr(0,j);
                for(int k=0;k<=n;k++){
                    string suff=word.substr(k,n);
                    mp[pref+"#"+suff]=i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string word=pref+"#"+suff;
        if(mp.count(word))return mp[word];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */