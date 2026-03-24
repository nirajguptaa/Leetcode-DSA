class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD=12345;
        int r=grid.size();
        int c=grid[0].size();
        int n=r*c;
        vector<int>arr;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr.push_back(grid[i][j] % MOD);
            }
        }
        vector<int>pref(n,1),suff(n,1);
        for(int i=1;i<n;i++){
            pref[i]=(pref[i-1]*arr[i-1])%MOD;
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=(suff[i+1]*arr[i+1])%MOD;
        }
        vector<vector<int>>p(r,vector<int>(c));
        for(int i=0;i<n;i++){
            int val=(pref[i]*suff[i])%MOD;
            p[i/c][i%c]=val;
        }
        return p;
    }
};