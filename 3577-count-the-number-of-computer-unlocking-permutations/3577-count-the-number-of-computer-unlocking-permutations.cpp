class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int root=complexity[0];
        sort(complexity.begin(),complexity.end());
        int n=complexity.size();
        int mod=1e9+7;
        long long count=1;
        if(complexity[0]<root){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(complexity[i]>root){
                count=(count*i)%mod;
            }else{
                return 0;
            }
        }
        return count%mod;
        
    }
};