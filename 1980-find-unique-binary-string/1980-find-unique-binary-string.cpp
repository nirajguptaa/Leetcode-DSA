class Solution {
public:
    string f(string &str,unordered_set<string>&seen,int len){
        if(str.size()==len){
            if(seen.find(str)==seen.end()){
                return str;
            }
            return "";
        }
        str+='0';
        string res=f(str,seen,len);
        if(res!="")return res;
        str.pop_back();
        
        str+='1';
        res=f(str,seen,len);
        if(res!="")return res;
        str.pop_back();
        return "";

    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>seen(nums.begin(),nums.end());
        
        int len=nums[0].size();
        string str="";
        return  f(str,seen,len);
        
    }
};