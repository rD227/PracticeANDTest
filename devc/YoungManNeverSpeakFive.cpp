#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<char> vc;
    char c;
    while (cin.get(c)) {
        if (c == '\n') {
            break;
        }
        if (c == '5') {
            c = '*';
        }
        vc.push_back(c);
    }
    for (const auto &element : vc) {
        cout << element;
    }
}