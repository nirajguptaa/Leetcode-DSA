class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        for(char ch:t){
            freq[ch]++;
        }
        int l=0,r=0;
        int n=s.size();
        int req=t.size();
        int minlen=INT_MAX;
        int startInd=0;
        while(r<n){
            if(freq[s[r]]>0){
                req--;
            }
            freq[s[r]]--;
            r++;
            while(req==0){
                if(r-l<minlen){
                    minlen=r-l;
                    startInd=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        if(minlen==INT_MAX)return "";
        return s.substr(startInd,minlen);
            
            
    }
};