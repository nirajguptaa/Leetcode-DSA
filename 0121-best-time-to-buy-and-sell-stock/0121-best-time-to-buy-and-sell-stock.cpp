class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mP=0;
        int minEle=INT_MAX;
        for(int i=0;i<n;i++){
            minEle=min(minEle,prices[i]);
            mP=max(mP,prices[i]-minEle);
        }
        return mP;
    }
};