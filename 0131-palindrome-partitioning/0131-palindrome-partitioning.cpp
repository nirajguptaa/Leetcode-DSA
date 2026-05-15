class Solution {
public:
    bool isPal(string &s,int l,int h){
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++,h--;
        }
        return true;
    }
    void f(int i,string s, vector<string>&temp,vector<vector<string>>&ans){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int start=i;start<s.size();start++){
            if(isPal(s,i,start)){
                temp.push_back(s.substr(i,start-i+1));
                f(start+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(0,s,temp,ans);
        return ans;
    }
};