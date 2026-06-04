class Solution {
public:
    int isWavi(int n){
        string num=to_string(n);
        int len=num.size();
        int count=0;
        for(int i=1;i<len-1;i++){
            if((num[i-1]< num[i] && num[i+1]<num[i]) || (num[i-1]> num[i] && num[i+1]>num[i])){

                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            count+=isWavi(i);
        }
        return count;
    }
};