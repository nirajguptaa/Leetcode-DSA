class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>freq;
        for(string word:words){
            freq[word]++;
        }
        vector<int>ans;
        int wordLen=words[0].size();
        int totalWords=words.size();
        int totalLen=words.size()*words[0].size();
        for(int i=0;i<wordLen;i++){
            unordered_map<string,int>window;
            int left=i;
            int count=0;
            for(int right=i;right+wordLen<=s.size();right+=wordLen){
                string curr=s.substr(right,wordLen);
                if(freq.count(curr)){
                    window[curr]++;
                    count++;
                    while(window[curr]>freq[curr]){
                        string leftWord=s.substr(left,wordLen);
                        window[leftWord]--;
                        left+=wordLen;
                        count--;
                    }
                    if(count==totalWords){
                        ans.push_back(left);
                        string leftWord=s.substr(left,wordLen);
                        window[leftWord]--;
                        left+=wordLen;
                        count--;
                    }
                }else{
                    window.clear();
                    count=0;
                    left=right+wordLen;
                }

            }
        }
        return ans;
    }
};