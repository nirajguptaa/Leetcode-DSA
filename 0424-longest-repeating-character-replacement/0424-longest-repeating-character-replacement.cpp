class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int maxFreq=0;
        int ans=0;
        vector<int>freq(26);
        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            while((r-l+1)-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};