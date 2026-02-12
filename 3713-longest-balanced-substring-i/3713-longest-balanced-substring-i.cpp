class Solution {
public:
    bool isBal(vector<int>& freq) {
        int val = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (val == 0)
                    val = freq[i];
                else if (freq[i] != val)
                    return false;
            }
            
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (isBal(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
    

};