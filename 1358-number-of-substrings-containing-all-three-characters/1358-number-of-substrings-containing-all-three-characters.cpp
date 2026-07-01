class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>ls(3,-1);
        int count=0;
        for(int i=0;i<s.size();i++){
            ls[s[i]-'a']=i;
            if(ls[0]!=-1 && ls[1]!=-1 && ls[2] !=-1){
                count+=1+min({ls[0],ls[1],ls[2]});
            }
        }
        return count;


    }
};