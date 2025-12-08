class Solution {
public:
    int countTriples(int n) {
        int count=0;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         for(int k=1;k<=n;k++){
        //             if(i*i+j*j==k*k){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i*i+j*j<=n*n){
                    int sq=i*i+j*j;
                    double sqr=sqrt(sq);
                    if(sqr==(int)sqr){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};