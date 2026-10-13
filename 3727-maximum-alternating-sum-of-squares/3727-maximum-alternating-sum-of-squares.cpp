class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int>maxHeap;
        
        for(int i=0;i<n;i++){
            maxHeap.push(nums[i]*nums[i]);
            
        }
        int half=(n+1)/2;
        long long ans=0;
        int count=0;
        while(count<half){
            int top=maxHeap.top();
            maxHeap.pop();
            ans+=top;
            count++;
        }
       
        while(!maxHeap.empty()){
            int top=maxHeap.top();
            maxHeap.pop();
            ans-=top;
        }
        return ans;
    }
};