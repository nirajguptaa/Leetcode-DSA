class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int a,int b){
            int setbitA=__builtin_popcount(a);
            int setbitB=__builtin_popcount(b);
            if(setbitA!=setbitB)return setbitA<setbitB;
            return a<b;
        });
        return arr;
    }
};