class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9){
            return "";
        }
        string ans="";
       
        while(sum>8){
            ans+="9";
            sum-=9;
        }
        int size=ans.size();
        if(size<num){
            ans+=to_string(sum);
            size++;
        }


        while(size<num){
            ans+=to_string(0);
            size++;
        }
        return ans;

    }
};