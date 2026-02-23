class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        if(k>s.size())return false;
        for(int i=0;i<=s.size()-k;i++){
            string str=s.substr(i,k);
            st.insert(str);
        }
        if(st.size()==(1<<k)){
            return true;
        }else{
            return false;
        }
    }
};