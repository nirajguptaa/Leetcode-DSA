class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int dist = INT_MIN;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>pq;

        // val listnum eleIdx
        int currMax=INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            currMax = max(currMax, nums[i][0]);
        }


        int start=0;
        int end = INT_MAX;
        while (true) {
            auto [val, row, col] = pq.top();
            pq.pop();
            if(currMax-val<end-start){
                start=val;
                end=currMax;
            }
            if(col+1==nums[row].size()){
                break;
            }
                
            if (col + 1 < nums[row].size()) {
                pq.push({nums[row][col + 1], row, col + 1});
                currMax=max(currMax,nums[row][col+1]);
            }
        }
        return {start,end};
    }
};