class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto k:knowledge){
            mp.insert({k[0],k[1]});
        }
        string ans="";
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                int j=i+1;
                string key="";
                while(s[j]!=')'){
                    key+=s[j];
                    j++;
                }
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }else{
                    ans+="?";
                }
                i=j;

            }
            if(i<len && s[i]==')'){
                continue;
            }
            if(i<len){

                ans+=s[i];
            }
        }
        return ans;
    }
};