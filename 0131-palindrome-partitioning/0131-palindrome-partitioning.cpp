class Solution {
public:
    bool palindrome(string &s,int l,int h){
        
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        backtrack(0,s,path,ans);
        return ans;
    }
    void backtrack(int i,string s,vector<string>&path,vector<vector<string>>&ans){
        int n=s.size();
        if(i==n){
            ans.push_back(path);
            return ;
        }
        for(int start=i;start<n;start++){
            if(palindrome(s,i,start)){
                path.push_back(s.substr(i,start-i+1));
                backtrack(start+1,s,path,ans);
                path.pop_back();
            }
        }
        
    }

};