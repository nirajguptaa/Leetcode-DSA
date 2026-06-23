class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>res;
        for(string s:strs){
            vector<int>freq(26,0);
            for(char ch:s){
                freq[ch-'a']++;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+="#"+to_string(freq[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto it:res){
            ans.push_back(it.second);
        }
        return ans;
    }
};