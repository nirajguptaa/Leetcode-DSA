class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char ch:text){
            freq[ch-'a']++;
        }
        int minSingleFreq=INT_MAX;
        int minDoubleChar=INT_MAX;
        minSingleFreq=min(minSingleFreq,freq[0]);
        minSingleFreq=min(minSingleFreq,freq[1]);
        minSingleFreq=min(minSingleFreq,freq[13]);
        minDoubleChar=min(minDoubleChar,freq[11]);
        minDoubleChar=min(minDoubleChar,freq[14]);
        minDoubleChar/=2;
        
        return min(minSingleFreq,minDoubleChar);

    }
};