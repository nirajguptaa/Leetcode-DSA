class Solution {
public:
    bool isOperator(string op){
        return op=="+"||op=="-"||op=="*"||op=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(string s:tokens){
            if(isOperator(s)){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                int ans;
                if(s=="+")ans=num2+num1;
                else if(s=="-")ans=num2-num1;
                else if(s=="*")ans=num2*num1;
                else ans=num2/num1;
                st.push(ans);
            }else{
                st.push(stoi(s));
            }
            
        }
        return st.top();
    }
};