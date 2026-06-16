class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minEle=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<n;i++){
            minEle=min(minEle,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minEle);
        }
        return maxProfit;
    }
};