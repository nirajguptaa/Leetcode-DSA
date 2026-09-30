class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        int len=seq.size();
        vector<int>ans(len,0);
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                depth+=1;
                ans[i]=depth%2;
            }else{
                ans[i]=depth%2;
                depth-=1;
            }
        }
        return ans;
    }
};