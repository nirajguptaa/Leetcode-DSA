class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        vector<pair<int,int>>bestEnd;
        bestEnd.push_back({0,0});
        int ans=0;
        int maxVal=0;
        for(auto &a:events){
            int start=a[0];
            int end=a[1];
            int value=a[2];
            int l=0,r=bestEnd.size()-1;
            while(l<r){
                int mid=(l+r+1)/2;
                if(bestEnd[mid].first<start){
                    l=mid;
                }else{
                    r=mid-1;
                }
            }
            ans=max(ans,value+bestEnd[l].second);
            maxVal=max(maxVal,value);
            bestEnd.push_back({end,maxVal});
        }
        return ans;

    }
};