#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int pos = 0;
    int posHer = x;
    vector<int> tissue;
    for (int i = 0; i < n; i++) {
        int z;
        cin >> z;
        tissue.push_back(z);
    }
    sort(tissue.begin(), tissue.end(), greater<int>());
    int countSteap = 0;
    for (int i = 0; i < n; i++) {
        if (pos + tissue.at(i) < posHer + y) {
            countSteap++;
            pos += tissue.at(i);
            posHer += y;
        } else {
            countSteap++;
            cout << countSteap << endl;
            return;
        }
    }
    if (countSteap == n) {
        cout << -1 << endl;
    }
}

int main() {
    int allIn;
    cin >> allIn;
    for (int i = 0; i < allIn; i++) {
        solve();
    }
}