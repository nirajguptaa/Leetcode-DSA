class Solution {
public:
    int smallestNumber(int n, int t) {
        int number=n;
        while(true){
            int prod=1;
            int temp=number;
            while(temp>0){
                int r=temp%10;
                prod*=r;
                temp=temp/10;
            }
            if(prod%t==0){
                return number;
            }
            number++;
            
        }
        
        
        
    }
};