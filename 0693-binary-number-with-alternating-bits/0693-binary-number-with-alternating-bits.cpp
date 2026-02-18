class Solution {
public:
    bool hasAlternatingBits(int n) {
        int lastbit=-1;
        while(n!=0){
            int bit=n%2;
            if(bit==lastbit){
                return false;
            }
            lastbit=bit;
            n/=2;
        }
        return true;
    }
};