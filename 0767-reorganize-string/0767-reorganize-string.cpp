class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int maxFreq=0;
        char maxFreqCh;
        for(auto &it:mp){
            if(it.second>maxFreq){
                maxFreq=it.second;
                maxFreqCh=it.first;
            }
        }
        int n=s.size();
        if(maxFreq>(n+1)/2){
            return "";
        }
        string ans(n,' ');
        int idx=0;
        while(mp[maxFreqCh]>0){
            ans[idx]=maxFreqCh;
            idx+=2;
            mp[maxFreqCh]--;
        }
        for(auto &it:mp){
            char ch=it.first;
            int freq=it.second;
            while(freq>0){
                if(idx>=n){
                    idx=1;
                }
                ans[idx]=ch;
                idx+=2;
                freq--;
            }
        }
        return ans;
        
    }
};