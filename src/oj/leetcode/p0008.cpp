//
// Created by 李睿 on 2016/11/18.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long n = 0;
        int sign = 1;
        bool s = false;
        bool inNumber = false;
        bool completed = false;
        for (char c : str) {
            switch (c) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    n = n * 10 + c - '0';
                    inNumber = true;
                    break;
                case '-':
                    if (s) {
                        return 0;
                    } else {
                        sign = -1;
                        s = true;
                        inNumber = true;
                    }
                    break;
                case '+':
                    if (s) {
                        return 0;
                    } else {
                        s = true;
                        inNumber = true;
                    }
                    break;
                case ' ':
                case '\t':
                    if (inNumber) {
                        completed = true;
                    }
                    break;
                default:
                    completed = true;
                    break;
            }

            if (completed) {
                break;
            }

            if (sign == -1 && n * sign < numeric_limits<int>::min()) {
                return numeric_limits<int>::min();
            } else if (sign == 1 && n > numeric_limits<int>::max()) {
                return numeric_limits<int>::max();
            }
        }

        n *= sign;
        if (n < numeric_limits<int>::min()) {
            return numeric_limits<int>::min();
        } else if (n > numeric_limits<int>::max()) {
            return numeric_limits<int>::max();
        } else {
            return static_cast<int>(n);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    cout << solution.myAtoi("- 123") << endl;
    cout << solution.myAtoi("- 12 3") << endl;
    cout << solution.myAtoi(" 2425 ") << endl;
    cout << solution.myAtoi(" - 321") << endl;
    cout << solution.myAtoi("-2147483648") << endl;
    cout << solution.myAtoi("2147483648") << endl;
    cout << solution.myAtoi("9223372036854775809") << endl;
}
