class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp0(zero + 1, vector<long long>(one + 1));
        vector<vector<long long>> dp1(zero + 1, vector<long long>(one + 1));
        dp0[0][0]=dp1[0][0]=1;
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                if(i>0){
                    for(int k=1;k<=limit && i-k>=0 ;k++){
                        dp0[i][j]=(dp0[i][j]+dp1[i-k][j])%MOD;
                    }
                }

                if(j>0){
                    for(int k=1;k<=limit && j-k>=0 ;k++){
                        dp1[i][j]=(dp1[i][j]+dp0[i][j-k])%MOD;
                    }
                }
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % MOD;

    }
};