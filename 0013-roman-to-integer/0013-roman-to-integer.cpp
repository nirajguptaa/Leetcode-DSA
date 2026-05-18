class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>romans={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int number=0;
        int len=s.size();
        for(int i=0;i<len;i++){
            if(i+1<len && romans[s[i]]<romans[s[i+1]]){
                number-=romans[s[i]];
            }else{
                number+=romans[s[i]];
            }
        }
        return number;
    }
};