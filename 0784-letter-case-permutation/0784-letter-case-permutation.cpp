class Solution {
public:
    void f(int idx,string s,vector<string>&ans){
        if(idx==s.size()){
            ans.push_back(s);
            return ;
        }
        f(idx+1,s,ans);
        if(isalpha(s[idx])){
            char ch=s[idx];
            if(islower(ch)){
                s[idx]=toupper(s[idx]);
                f(idx+1,s,ans);
                s[idx]=tolower(s[idx]);
            }else if(isupper(ch)){
                s[idx]=tolower(s[idx]);
                f(idx+1,s,ans);
                s[idx]=toupper(s[idx]);
            }

        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string curr="";
        f(0,s,ans);
        return ans;
    }
};