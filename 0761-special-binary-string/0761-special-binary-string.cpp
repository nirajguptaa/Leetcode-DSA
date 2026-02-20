class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>parts;
        int bal=0;
        int last=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                bal+=1;
            }else{
                bal-=1;
            }
            if(bal==0){
                string inner=s.substr(last+1,i-last-1);
                parts.push_back("1"+makeLargestSpecial(inner)+"0");
                last=i+1;
            }
        }
        sort(parts.begin(),parts.end(),greater<string>());
        string ans="";
        for(string &s:parts){
            ans+=s;
        }
        return ans;
    }
};