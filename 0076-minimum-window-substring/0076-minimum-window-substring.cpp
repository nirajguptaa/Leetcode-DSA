class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int>freq;
        for(char ch:t){
            freq[ch]++;
        }
        int start=0;
        int l=0,r=0,n=s.size(),req=t.size();
        int minlen=INT_MAX;
        while(r<n){
            if(freq[s[r]]>0){
                req--;
            }
            freq[s[r]]--;
            r++;
            while(req==0){
                if(r-l<minlen){
                    minlen=r-l;
                    start=l;
                }
                freq[s[l]]++;
                
                if(freq[s[l]]>0){
                    req++;
                }
                l++;
            }
        }
        if(minlen==INT_MAX)return "";
        return s.substr(start,minlen);


    }
};