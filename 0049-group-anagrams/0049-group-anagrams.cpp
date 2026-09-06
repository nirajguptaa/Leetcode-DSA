class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(string str:strs){
            vector<int>freq(26,0);
            for(char ch:str){
                freq[ch-'a']++;
            }
            string k="";
            for(int i=0;i<26;i++){
                k+=to_string(freq[i])+"#";
            }
            mp[k].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};