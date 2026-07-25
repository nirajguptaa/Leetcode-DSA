class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        if(n>m)return "";
        int l=0,r=0,req=n,start=0;
        int minLen=INT_MAX;
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++){
            freq[t[i]]++;
        }
        while(r<m){
            if(freq[s[r]]>0){
                req--;
            }
            freq[s[r]]--;
            r++;
            while(req==0){
                if(r-l<minLen){
                    minLen=r-l;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    req++;
                }
                l++;

            }
        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
            
    }
};