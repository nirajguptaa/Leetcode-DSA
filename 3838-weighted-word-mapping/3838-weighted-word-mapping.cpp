class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        
        for(string word:words){
            int sum=0;
            for(int i=0;i<word.size();i++){
                sum+=weights[word[i]-'a'];
            }
            sum%=26;
            ans+=char('z'-sum);
            
            
        }
        return ans;
    }
};