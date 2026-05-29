class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=haystack.size();
        
        for(int k=0;k<len;k++){
            int h=k,n=0;
            while(n<needle.size() && h<haystack.size()){
                if(haystack[h]==needle[n]){
                    h++;
                    n++;
                }else{
                    break;
                }
            }
            if(n==needle.size()){
                return k;
            }
                
        }
        return -1;
    }
};