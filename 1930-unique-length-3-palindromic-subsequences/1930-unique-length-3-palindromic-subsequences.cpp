class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(first[ch-'a']==-1){
                first[ch-'a']=i;
            }
            last[ch-'a']=i;
        }

        int count=0;
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && last[i]>first[i]){

                set<char>seen;
                for(int j=first[i]+1;j<last[i];j++){
                    seen.insert(s[j]);
                }
                count+=seen.size();
            }
        }
        return count;
    }
};