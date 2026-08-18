class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        vector<char>temp;
        while(i<n){
            int j=i;
            char ch=chars[i];
            while(j<n && chars[j]==ch){
                j++;
            }
            temp.push_back(ch);
            int freq=j-i;
            if(freq>1){

                string s=to_string(freq);
                for(char c:s){
                    temp.push_back(c);
                }
            }
            i=j;

        }
        chars=temp;
        return temp.size();

    }
};