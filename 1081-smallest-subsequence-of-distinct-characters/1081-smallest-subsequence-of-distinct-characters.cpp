class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>vis(26,0);
        vector<int>last(26,0);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(vis[ch-'a'])continue;
            while(!ans.empty() && ch<ans.back() && last[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans+=ch;
            vis[ch-'a']=1;
        }
        return ans;
    }
};