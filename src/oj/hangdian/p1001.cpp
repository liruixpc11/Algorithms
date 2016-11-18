//
// Created by 李睿 on 16/7/12.
//

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    while (!cin.eof()) {
        cin >> n;
        cout << (1 + n) * n / 2 << endl;
    }
}
