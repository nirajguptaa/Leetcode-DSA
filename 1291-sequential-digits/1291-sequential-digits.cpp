class Solution {
public:
    void f(int val,int nextDigit,int low,int high,vector<int>&ans){
        if(low<=val && val<=high){
            ans.push_back(val);
        }
        if(val>high){
            return;
        }
        if(nextDigit>9){
            return;
        }
        int newVal=val*10+nextDigit;
        f(newVal,nextDigit+1,low,high,ans);
        
    }
        
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int start=1;start<=9;start++){

            f(start,start+1,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};