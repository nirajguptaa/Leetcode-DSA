class Solution {
public:
    int merge(vector<int>& nums,int l,int m,int h){

        int count=0;
        int j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=h && nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(m+1);
        }
        int i=l;j=m+1;
        vector<int>temp;
        while(i<=m && j<=h){
            if(nums[i]<=nums[j]){
                
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(nums[i++]);
        }
        while(j<=h){
            temp.push_back(nums[j++]);
        }
        for(int k=l;k<=h;k++){
            nums[k]=temp[k-l];
        }
        return count;
    }
    int countReverse(vector<int>& nums,int l,int h){
        int count=0;
        if(l<h){
            int m=l+(h-l)/2;
            count+=countReverse(nums,l,m);
            count+=countReverse(nums,m+1,h);
            count+=merge(nums,l,m,h);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return countReverse(nums,0,n-1);
    }
};