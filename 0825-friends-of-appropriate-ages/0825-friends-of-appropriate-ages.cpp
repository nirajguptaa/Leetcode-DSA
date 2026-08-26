class Solution {
public:
    int count = 0;
    bool valid(int x, int y) {

        if (y <= 0.5 * x + 7) {
            return false;
        }
        if (y > x)
            return false;
        if (y > 100 && x < 100)
            return false;

        return true;
    }

    int numFriendRequests(vector<int>& ages) {

        vector<int> freq(121, 0);
        for (int age : ages) {
            freq[age]++;
        }
        for (int x = 1; x <= 120; x++) {
            if (freq[x] == 0) {
                continue;
            }
            for (int y = 1; y <= 120; y++) {
                if (freq[y] == 0)
                    continue;
                if (!valid(x, y))
                    continue;
                if (x == y) {
                    count += freq[x] * (freq[x] - 1);
                } else {
                    count += freq[x] * freq[y];
                }
            }
        }
        return count;
    }
};