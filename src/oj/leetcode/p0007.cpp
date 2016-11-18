//
// Created by 李睿 on 2016/11/18.
//

#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long r = 0;
        int sign = x < 0 ? -1 : 1;
        for (int n = sign * x; n != 0; n /= 10) {
            int remain = n % 10;
            r = r * 10 + remain;
        }

        r *= sign;
        return r <= numeric_limits<int>::max() && r >= numeric_limits<int>::min() ? static_cast<int>(r) : 0;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    cout << solution.reverse(123) << endl;
    cout << solution.reverse(3281) << endl;
    cout << solution.reverse(-3281) << endl;
    cout << solution.reverse(-3200) << endl;
    cout << solution.reverse(1000000009) << endl;
}
