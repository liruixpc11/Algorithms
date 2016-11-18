//
// Created by 李睿 on 2016/11/18.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string sub;

        for (int mid = 0 ; mid < s.size(); ++mid) {
            int right = min(mid * 2 + 1, static_cast<int>(s.size()));
            int left = max(-1, mid - (static_cast<int>(s.size()) - mid));

            int r = 1;
            for (; mid + r < right && mid - r > left && s[mid + r] == s[mid - r]; ++r) {
            }

            if (((r - 1) * 2 + 1) > sub.size()) {
                sub.assign(s.begin() + (mid - r + 1), s.begin() + (mid + r));
            }

            if (mid + 1 < s.size() && s[mid] == s[mid + 1]) {
                r = 1;
                int mid2 = mid + 1;
                right += 1;
                for (; mid - r > left && mid2 + r < right && s[mid - r] == s[mid2 + r]; ++r) {
                }

                if (r * 2 > sub.size()) {
                    sub.assign(s.begin() + (mid - r + 1), s.begin() + (mid2 + r));
                }
            }
        }

        return sub;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.longestPalindrome("baab") << endl;
    cout << solution.longestPalindrome("badab") << endl;
    cout << solution.longestPalindrome("cddb") << endl;
}