//
// Created by 李睿 on 2016/11/18.
//

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int columnsPerCycle = numRows - 1;
        int cycle = (numRows - 1) * 2;
        int numCycles = static_cast<int>(s.size() / cycle);
        if (s.size() % cycle != 0) {
            numCycles += 1;
        }
        int numColumns = numCycles * columnsPerCycle;

        string ss(numColumns * numRows, -1);
        for (int i = 0; i <= numCycles; i++) {
            for (int j = 0; j < cycle; j++) {
                int index = i * cycle + j;
                if (index >= s.size()) {
                    break;
                }

                int column = i * columnsPerCycle + (j / numRows) * (j % numRows + 1);
                int row = j < numRows ? j : numRows - (j % numRows) - 2;
                ss[row * numColumns + column] = s[index];
            }
        }

        return string(ss.begin(), remove_if(ss.begin(), ss.end(), [](char c) {
            return c == -1;
        }));
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    cout << solution.convert("abcdefghijk", 3) << endl;
    cout << solution.convert("abcdefghijk", 4) << endl;
}