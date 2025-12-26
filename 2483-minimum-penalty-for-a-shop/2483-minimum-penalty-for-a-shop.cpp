class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>prefSum(n+1,0);
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                prefSum[0]+=1;
            }
        }
        int ans=prefSum[0];
        int ind=0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='Y'){
                prefSum[i]=prefSum[i-1]-1;
            }else{
                prefSum[i]=prefSum[i-1]+1;
            }
            if(ans>prefSum[i]){
                ans=prefSum[i];
                ind=i;
            }
            
        }
        return ind;
        
    }
};