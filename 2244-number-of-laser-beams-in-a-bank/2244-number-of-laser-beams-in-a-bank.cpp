class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int count = 0;
        int total=0;
        for (int i = 0; i < bank[0].size(); i++) {
            if (bank[0][i] == '1') {
                count++;
            }
        }

        for (int i = 1; i < n; i++) {
            int currCount = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') {
                    currCount++;
                }
            }
            if(currCount!=0 ){
                total+=count*currCount;
                count=currCount;
            }
            
        }
        return total;
    }
};