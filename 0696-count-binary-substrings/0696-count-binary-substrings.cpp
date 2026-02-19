class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>arr;
        int count=0;
        int digit=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]-'0'==digit){
                count++;
            }else{
                if(digit!=-1){
                    arr.push_back(count);
                }
                digit=s[i]-'0';
                count=1;
            }
        }
        arr.push_back(count);
        int ans=0;
        for(int i=0;i<arr.size()-1;i++){
            ans+=min(arr[i],arr[i+1]);
        }
        return ans;
    }
};