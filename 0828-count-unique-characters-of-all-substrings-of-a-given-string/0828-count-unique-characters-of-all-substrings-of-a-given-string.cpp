class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++){
            pos[s[i]-'A'].push_back(i);
        }
        int ans=0;
        for(int ch=0;ch<26;ch++){
            int prev=-1;
            for(int i=0;i<pos[ch].size();i++){
                int curr=pos[ch][i];
                int next=(i==pos[ch].size()-1)?n:pos[ch][i+1];
                ans+=(curr-prev)*(next-curr);
                prev=curr;
            }
        }
        return ans;
    }
};