//
// Created by 李睿 on 2016/11/17.
//

#include <string>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <array>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 256> indices;
        fill(indices.begin(), indices.end(), -1);

        deque<char> sub;
        size_t longest = 0;
        for (int i = 0, base = 0; i < s.size(); i++) {
            char c = s[i];
            int ic = indices[c];
            if (ic == -1) {
                indices[c] = i;
                sub.push_back(c);
            } else {
                if (sub.size() > longest) {
                    longest = sub.size();
                }

                for (int ix = base; ix < ic; ix++) {
                    indices[s[ix]] = -1;
                    sub.pop_front();
                }

                sub.pop_front();
                indices[c] = i;
                base = ic + 1;
                sub.push_back(c);
            }
        }

        return max(sub.size(), longest);
    }
};

int main(int argc, char *argv[]) {
    string s = "wersdfoiwrd";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
}