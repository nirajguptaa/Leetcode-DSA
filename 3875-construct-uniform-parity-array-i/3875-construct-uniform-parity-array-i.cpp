class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>even;
        vector<int>odd;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                even.push_back(nums1[i]);
            }else{
                for(int j=0;j<n;j++){
                    if(i!=j && (nums1[i]-nums1[j])%2==0){
                        even.push_back(nums1[j]);
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                odd.push_back(nums1[i]);
            }else{
                for(int j=0;j<n;j++){
                    if(i!=j && (nums1[i]-nums1[j])%2!=0){
                        odd.push_back(nums1[j]);
                        break;
                    }
                }
            }
        }
        
        return (even.size()==n || odd.size()==n);
    }
};