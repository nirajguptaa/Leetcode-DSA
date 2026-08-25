class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prevSmall(n),nextSmall(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                prevSmall[i]=-1;
            }else{
                prevSmall[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nextSmall[i]=n;
            }else{
                nextSmall[i]=st.top();
            }
            st.push(i);
        }
        int maxRect=0;
        for(int i=0;i<n;i++){
            int len=nextSmall[i]-prevSmall[i]-1;
            maxRect=max(maxRect,len*heights[i]);
        }
        return maxRect;
    }
};