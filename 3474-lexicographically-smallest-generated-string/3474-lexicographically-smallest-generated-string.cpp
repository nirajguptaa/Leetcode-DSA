class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string ans(len, 'a');
        vector<int> fixed(len, 0);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (fixed[i + j] && ans[i + j] != str2[j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                    fixed[i + j] = 1;
                }
            }
        }

   
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool alreadyDifferent = false;
                int changeIndex = -1;

                // scan from RIGHT → IMPORTANT
                for (int j = m - 1; j >= 0; j--) {
                    if (ans[i + j] != str2[j]) {
                        alreadyDifferent = true;
                    }
                    if (changeIndex == -1 && fixed[i + j] == 0) {
                        changeIndex = i + j;
                    }
                }

                // already safe
                if (alreadyDifferent) continue;

                // need to break
                if (changeIndex != -1) {
                    ans[changeIndex] = (str2[changeIndex - i] == 'a') ? 'b' : 'a';
                } else {
                    return "";
                }
            }
        }

        return ans;
    }
};