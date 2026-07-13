class Solution {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int,int>delay;
    int maxSize = 0, minSize = 0;
    void pruneMax(){
        while(!maxHeap.empty() && delay[maxHeap.top()]>0){
            delay[maxHeap.top()]--;
            maxHeap.pop();
        }
    }
    void pruneMin(){
        while(!minHeap.empty() && delay[minHeap.top()]>0){
            delay[minHeap.top()]--;
            minHeap.pop();
        }
    }
    void balance(){
        if(maxSize>minSize+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxSize--;
            minSize++;
            pruneMax();
        }else if(maxSize<minSize){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minSize--;
            maxSize++;
            pruneMin();
        }
    }
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            maxSize++;
        } else {
            minHeap.push(num);
            minSize++;
        }
        balance();
    }
    void removeNum(int num){
        delay[num]++;
        if(num<=maxHeap.top()){
            maxSize--;
            if(num==maxHeap.top()){
                pruneMax();
            }
        }else{
            minSize--;
            if(!minHeap.empty() && num==minHeap.top()){
                pruneMin();
            }
        }
        balance();
    }
    double getMedian(int k) {
        if (k % 2 != 0) {
            return maxHeap.top();
        } else {
            return ((long long)maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for(int i=0;i<k;i++){
            addNum(nums[i]);
        }
        ans.push_back(getMedian(k));
        for(int i=k;i<nums.size();i++){
            removeNum(nums[i-k]);
            addNum(nums[i]);
            ans.push_back(getMedian(k));
        }
        return ans;
    }
};