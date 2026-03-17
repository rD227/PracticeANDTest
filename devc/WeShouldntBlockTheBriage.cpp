#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> strv;
    strv.reserve(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strv.push_back(str);
    }
    unordered_map<string, int> umap;
    for (auto &astr : strv) {
        umap[astr]++;
    }
    int maxNumber = 0;
    for (auto &astr : strv) {
        string oppoAstr = astr;
        for (auto &c : oppoAstr) {
            // if
            c = (c == '0' ? '1' : '0');
        }
        int allInMatches =
            umap[astr] + (umap.count(oppoAstr) ? umap[oppoAstr] : 0);
        // then we need to get the number of '1' in this row....
        int numberInTheRow = 0;
        for (auto &c : astr) {
            numberInTheRow += (c == '1' ? 1 : 0);
        }
        maxNumber = max(maxNumber, numberInTheRow);
    }
    cout << maxNumber << endl;
    return 0;
}