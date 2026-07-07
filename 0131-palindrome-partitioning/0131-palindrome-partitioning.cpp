class Solution {
public:
    bool isPalin(int l,int h,string s){
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++,h--;
        }
        return true;
    }
    void f(int idx,string s,vector<string>&temp,vector<vector<string>>&ans){
        int n=s.size();
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(int start=idx;start<n;start++){
            if(isPalin(idx,start,s)){
                temp.push_back(s.substr(idx,start-idx+1));
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