class Solution {
public:
    int numSteps(string s) {
        int count=0;
        
        while(s!="1"){
            int n=s.size();
            if(s[n-1]=='0'){
                s.pop_back();
            }else{
                int i=n-1;
                while(i>=0 && s[i]=='1'){
                    s[i]='0';
                    i--;
                }
                if(i>=0){
                    s[i]='1';
                }else{
                    s='1'+s;
                }
            }
            count++;
        }
        return count;
    }
};