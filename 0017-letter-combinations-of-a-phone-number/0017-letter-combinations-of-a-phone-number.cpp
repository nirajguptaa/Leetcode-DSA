class Solution {
public:
    void f(vector<string>comb,vector<string>&ans,string digits,int idx,string curr){
        int n=digits.size();
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        int digit=digits[idx]-'0';
        string letters=comb[digit];
        for(char c:letters){
            f(comb,ans,digits,idx+1,curr+c);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>comb={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.empty())return ans;
        f(comb,ans,digits,0,"");
        return ans;
    }
};