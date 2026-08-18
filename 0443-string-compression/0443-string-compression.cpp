class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int i=0;
        while(i<n){
            int j=i;
            char ch=chars[i];
            while(j<n && chars[j]==ch){
                j++;
            }
            int freq=j-i;
            chars[write++]=ch;
            if(freq>1){
                string s=to_string(freq);
                for(char c:s){
                    chars[write++]=c;
                }

            }
            i=j;
        }
        return write;
    }
};