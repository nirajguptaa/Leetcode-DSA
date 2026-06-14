class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            unordered_map<int,int>freqCount;
            int maxF=0;
            for(int j=i;j<n;j++){
                if(freq[nums[j]]>0){
                    freqCount[freq[nums[j]]]--;
                }
                freq[nums[j]]++;
                freqCount[freq[nums[j]]]++;
                int len=j-i+1;
                if(len==1){
                    continue;
                }
                maxF=max(maxF,freq[nums[j]]);
                int distinctCount=freq.size();
                if(distinctCount==1){
                    ans=max(ans,len);
                }
                if(maxF%2==0 && freqCount[maxF/2]>0 && (freqCount[maxF]+freqCount[maxF/2]==distinctCount)){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};