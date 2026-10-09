class Solution {
public:
    int minInsertions(string s) {
        int need=0;
        int insertion=0;
        for(char ch:s){
            if(ch=='('){
                if(need%2==1){
                    insertion+=1;
                    need--;
                }
                need+=2;
            }else{
                need--;
                if(need<0){
                    insertion++;
                    need=1;
                }
            }

        }
        return need+insertion;
    }
};