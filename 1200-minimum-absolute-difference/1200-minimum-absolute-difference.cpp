class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn=INT_MAX;
        
        for(int i=1;i<arr.size();i++){
            minn=min(arr[i]-arr[i-1],minn);
        }
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==minn){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};