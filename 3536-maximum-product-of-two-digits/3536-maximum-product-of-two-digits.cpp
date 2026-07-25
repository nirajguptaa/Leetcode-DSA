class Solution {
public:
    int maxProduct(int n) {
        vector<int>digit;
        while(n>0){
            int d=n%10;
            n/=10;
            digit.push_back(d);
        }
        sort(digit.rbegin(),digit.rend());
        return digit[0]*digit[1];
    }
};