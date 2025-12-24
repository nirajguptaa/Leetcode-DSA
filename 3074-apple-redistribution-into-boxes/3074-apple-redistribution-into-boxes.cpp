class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.begin(),apple.end(),greater<int>());
        sort(capacity.begin(),capacity.end(),greater<int>());
        int n=apple.size(),m=capacity.size();
        int j=0;
        int curr=capacity[0];
        int i=0;
        while(i<n){
            if(curr>=apple[i]){
                curr-=apple[i];
                i++;
                
            }else{
                j++;
                curr+=capacity[j];
            }
        }
        
        return j+1;
    }
};