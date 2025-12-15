class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int last=-1;
        long long  count=0;
        int cont=0;
        for(int i=0;i<prices.size();i++){
            if(last-prices[i]==1){
                cont++;
            }else{
                cont=0;
            }
                
            count=count+cont+1;
            last=prices[i];
            
                
        }
        return count;
    }
};