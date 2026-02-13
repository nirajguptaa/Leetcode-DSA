class Solution {
public:
    int helper(string s, char ch1, char ch2) {
        int maxL = 0;
        unordered_map<int, int> diffMap;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }
            if (s[i] == ch1)
                count1++;
            else if (s[i] == ch2)
                count2++;
            if (count1 == count2) {
                maxL = max(maxL, count1 + count2);
            }
            int diff = count1 - count2;
            if (diffMap.count(diff)) {
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                diffMap[diff] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxlen = 0;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                maxlen = max(maxlen, count);
                count = 1;
            }
        }
        maxlen = max(maxlen, count);

        // case 2
        maxlen = max(maxlen, helper(s, 'a', 'b'));
        maxlen = max(maxlen, helper(s, 'b', 'c'));
        maxlen = max(maxlen, helper(s, 'a', 'c'));

        //case3

        unordered_map<string, int> diffMap;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                a++;
            else if (s[i] == 'b')
                b++;
            else
                c++;
            if (a == b && b == c) {
                maxlen = max(maxlen, a + b + c);
            }
            int diffAB = a - b;
            int diffAC = a - c;
            string key = to_string(diffAB) + "_" + to_string(diffAC);
            if (diffMap.count(key)) {
                maxlen = max(maxlen, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }
        return maxlen;
    }
};