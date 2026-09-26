#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Make variables static so they persist across all LeetCode test cases
    static vector<long long> even;
    static vector<long long> odd;
    static bool generated;

    long long ipow10(int exp) {
        long long res = 1;
        for (int i = 0; i < exp; ++i) res *= 10;
        return res;
    }

    void generatePalindromes() {
        if (generated) return;

        for (int len = 1; len <= 10; len++) {
            int halfLen = (len + 1) / 2;
            long long start = ipow10(halfLen - 1);
            long long end = ipow10(halfLen) - 1;

            for (long long i = start; i <= end; i++) {
                string s = to_string(i);
                string rev = s;
                reverse(rev.begin(), rev.end());

                string pal = (len % 2 == 0) ? (s + rev) : (s + rev.substr(1));
                long long palin = stoll(pal);

                if (palin > 0) {
                    if (palin % 2 == 0) {
                        even.push_back(palin);
                    } else {
                        odd.push_back(palin);
                    }
                }
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        generated = true;
    }

    long long minOperations(vector<int>& nums) {
        generatePalindromes();
        long long totalOps = 0;

        for (int x : nums) {
            const vector<long long>& pals = (x % 2 == 0 ? even : odd);
            auto it = lower_bound(pals.begin(), pals.end(), x);
            
            long long minDiff = LLONG_MAX;

            if (it != pals.end()) {
                long long diff = *it - x;
                minDiff = min(diff, minDiff);
            }

            if (it != pals.begin()) {
                auto prevIt = prev(it);
                long long diff = x - *prevIt;
                minDiff = min(diff, minDiff);
            }

            totalOps += minDiff / 2;
        }

        return totalOps;
    }
};

// Define static variables outside class definition (required in standard C++)
vector<long long> Solution::even;
vector<long long> Solution::odd;
bool Solution::generated = false;