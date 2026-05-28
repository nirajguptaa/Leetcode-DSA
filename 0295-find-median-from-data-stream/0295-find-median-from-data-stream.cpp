class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    //maxheap - smaller half of numbers
    //minHeap- larger half of numbers
    void addNum(int num) {
        if(maxHeap.size()==0 || maxHeap.top()>num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        if(maxHeap.size()-1>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        if(maxHeap.size()>minHeap.size()){
            return maxHeap.top();
        }
        return (minHeap.top()+maxHeap.top())/2.0;  
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */