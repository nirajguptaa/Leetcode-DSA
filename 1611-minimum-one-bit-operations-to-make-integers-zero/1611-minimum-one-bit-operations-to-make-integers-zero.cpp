class Solution {
public:
    int f(int n,unordered_map<int,int>&mp){
        if(n<=1){
            return n;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        int k=0;
        int temp=n;
        while(temp>1){
            k++;
            temp>>=1;
        }
        int mask=1<<k;
        mp[n]=(1<<(k+1))-1-f(n^mask,mp);
        return mp[n];

    }
    int minimumOneBitOperations(int n) {
        unordered_map<int,int>mp;
        return f(n,mp);
    }
};