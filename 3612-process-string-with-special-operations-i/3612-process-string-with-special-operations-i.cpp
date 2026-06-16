class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char ch:s){
            if(ch=='*'){
                if(res.size()>0){

                    res.pop_back();
                }
            }else if(ch=='#'){
                res+=res;
            }else if(ch=='%'){
                string temp=res;
                reverse(temp.begin(),temp.end());
                res=temp;
            }else{
                res+=ch;
            }
        }
        return res;
    }
};