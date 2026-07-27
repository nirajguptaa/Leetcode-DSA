class Solution {
public:
    int mergeCount(int l,int m,int h,vector<long long>&prefix,int lower,int upper){
        int count=0;
        int low=m+1;
        int high=m+1;
        for(int i=l;i<=m;i++){
            while(low<=h && prefix[low]-prefix[i]<lower){
                low++;
            }
            while(high<=h && prefix[high]-prefix[i]<=upper){
                high++;
            }
            count+=high-low;
        }
        int i=l,j=m+1;
        vector<long long>temp;
        while(i<=m && j<=h){
            if(prefix[i]<=prefix[j]){
                temp.push_back(prefix[i]);
                i++;
            }else{
                temp.push_back(prefix[j]);
                j++;
            }
        }
        while(i<=m){
            temp.push_back(prefix[i]);
            i++;
        }
        while(j<=h){
            temp.push_back(prefix[j]);
            j++;
        }
        for(int k=l;k<=h;k++){
            prefix[k]=temp[k-l];
        }
        return count;
    }
    int mergeSort(int l,int h,vector<long long>&prefix,int lower,int upper){
        if(l>=h)return 0;
        int m=l+(h-l)/2;
        int count=0;
        count+=mergeSort(l,m,prefix,lower,upper);
        count+=mergeSort(m+1,h,prefix,lower,upper);
        count+=mergeCount(l,m,h,prefix,lower,upper);
        return count;

    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long >prefixSum(n+1);
        for(int i=0;i<n;i++){
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }
        return mergeSort(0,n,prefixSum,lower,upper);
    }
};