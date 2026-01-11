class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int h=arr.size();
        stack<int>St;
        vector<int>left(h),right(h);
        for(int i=0;i<h;i++){
            while(!St.empty() && arr[St.top()]>=arr[i]){
                St.pop();
            }
            left[i]=St.empty()?-1:St.top();
            St.push(i);
        }
        while(!St.empty())St.pop();
        for(int i=h-1;i>=0;i--){
            while(!St.empty() && arr[St.top()]>=arr[i]){
                St.pop();
            }
            right[i]=St.empty()?h:St.top();
            St.push(i);
        }
        int maxArea=0;
        for(int i=0;i<h;i++){
            int width=right[i]-left[i]-1;
            int area=width*arr[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]+=1;
                }else{
                    height[j]=0;
                }
            }
            int area=largestRectangleArea(height);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};