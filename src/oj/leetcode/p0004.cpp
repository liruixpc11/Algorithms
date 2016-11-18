//
// Created by 李睿 on 2016/11/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
        auto i1 = nums1.begin(), e1 = nums1.end();
        auto i2 = nums2.begin(), e2 = nums2.end();

        size_t length = (nums1.size() + nums2.size()) / 2 + 1;
        if (length == 0) {
            return 0;
        }

        bool single = (nums1.size() + nums2.size()) % 2 == 1;
        int x, y;
        for (size_t i = 0; i < length; i++) {
            int n;
            if (i1 == e1) {
                n = *i2;
                ++i2;
            } else if (i2 == e2) {
                n = *i1;
                ++i1;
            } else if (*i1 < *i2) {
                n = *i1;
                ++i1;
            } else {
                n = *i2;
                ++i2;
            }

            if (i == 0) {
                x = y = n;
            } else {
                x = y;
                y = n;
            }
        }

        if (single) {
            return y;
        } else {
            return (x + y) / 2.0;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    cout << solution.findMedianSortedArrays({}, {1}) << endl;
    cout << solution.findMedianSortedArrays({}, {1, 4}) << endl;
    cout << solution.findMedianSortedArrays({}, {1, 2, 3, 4}) << endl;
    cout << solution.findMedianSortedArrays({1, 3}, {2}) << endl;
    cout << solution.findMedianSortedArrays({1, 2}, {3, 4}) << endl;
}
