class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        int n=pushed.size();
        stack<int>s;
        while(i<n){
            s.push(pushed[i]);
            i++;
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        if(i==n && j==n){
            return true;
        }else{
            return false;
        }

    }
};