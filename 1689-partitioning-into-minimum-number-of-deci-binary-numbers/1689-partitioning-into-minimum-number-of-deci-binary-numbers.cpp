class Solution {
public:
    int minPartitions(string n) {
        int maxdig=INT_MIN;
        for(char ch:n){
            maxdig=max(maxdig,ch-'0');
        }
        return maxdig;
    }
};