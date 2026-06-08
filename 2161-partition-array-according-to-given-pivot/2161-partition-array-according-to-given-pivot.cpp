class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less,equal,more;
        for(int n:nums){
            if(n<pivot){
                less.push_back(n);
            }else if(n==pivot){
                equal.push_back(n);
            }else{
                more.push_back(n);
            }
        }
        vector<int>ans;
        for(int i:less){
            ans.push_back(i);
        }
        for(int i:equal){
            ans.push_back(i);
        }
        for(int i:more){
            ans.push_back(i);
        }
        return ans;

    }
};