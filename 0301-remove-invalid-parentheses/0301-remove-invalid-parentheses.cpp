class Solution {
public: 
    void f(int idx,string curr,string s,int removeLeft, int removeRight,int balance,unordered_set<string>&ans){

        if(idx==s.size() && removeLeft==0 && removeRight==0 && balance==0){
            ans.insert(curr);
            return ;
        }
        if(s.size()-idx<removeLeft+removeRight){
            return ;
        }
        if(idx>=s.size() || removeLeft<0 || removeRight<0 || balance<0){
            return ;
        }
        if(s[idx]=='('){
            if(removeLeft>0){
                //remove
                f(idx+1,curr,s,removeLeft-1,removeRight,balance,ans);
            }
            //keep
            f(idx+1,curr+s[idx],s,removeLeft,removeRight,balance+1,ans);
        }
        else if(s[idx]==')'){
            if(removeRight>0){
                //remove
                f(idx+1,curr,s,removeLeft,removeRight-1,balance,ans);
            }
            if(balance>0){
                //keep
                f(idx+1,curr+s[idx],s,removeLeft,removeRight,balance-1,ans);
            }

                

        }
        else{
            f(idx+1,curr+s[idx],s,removeLeft,removeRight,balance,ans);
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        int removeRight=0;
        int balance=0;
        for(char ch:s){
            if(ch=='('){
                balance++;
            }if(ch==')'){
                balance--;
                if(balance<0){
                    removeRight++;
                    balance=0;
                }
            }
        }
        int removeLeft=balance;
        unordered_set<string>ans;
        f(0,"",s,removeLeft,removeRight,0,ans);
        
        return vector<string>(ans.begin(),ans.end());
    }
};