class Solution {
public:
    void f(vector<int>&ans,int num){
        vector<int>temp;
        while(num>0){
            int r=num%10;;
            num/=10;
            temp.push_back(r);
        }
        int len=temp.size();
        for(int i=len-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            
            f(ans,nums[i]);
        }
        return ans;
    }
};