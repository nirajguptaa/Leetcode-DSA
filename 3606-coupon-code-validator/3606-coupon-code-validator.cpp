class Solution {
public:
    bool valid(string str){
        if(str==""){
            return false;
        }
        for(char c : str){
            if(!(isalnum(c) || c=='_')) return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>ans;
        int n=code.size();
        unordered_map<string,int>priority={
            {"electronics",1},
            {"grocery",2},
            {"pharmacy",3},
            {"restaurant",4}
        };
        vector<pair<int,string>>temp;
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(priority.count(businessLine[i]) && valid(code[i])){
                    temp.push_back({priority[businessLine[i]],code[i]});
                }
            }
        }
        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            if(a.first!=b.first){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        for(auto &p:temp){
            ans.push_back(p.second);
        }
        return ans;
    }
}; 