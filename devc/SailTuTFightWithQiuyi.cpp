#include <bits/stdc++.h>

using namespace std;

void solve(int n, int t) {
    int sum = 0;
    vector<int> vs;
    vs.reserve(n);
    vector<int> vy;
    vy.reserve(n);
    vector<int> differ;
    differ.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vs.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vy.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int dif = vs.at(i) - vy.at(i);
        differ.push_back(dif);
    }
    vector<int> newDiff = differ;
    sort(newDiff.begin(), newDiff.end());
    int spos = 0;
    int ypos = n;
    cout << "t is " << t << endl;
    for (int j = 0; j < t; j++) {
        cout << "spos is " << spos + 1 << " times now!!" << endl;
        if (j % 2 == 0) {
            if (newDiff[spos] < 0 /*&& i % 2 == 0*/) {
                newDiff[spos] = 0;
                spos++;
            }
        } else {
            if (newDiff[ypos - 1] > 0 /* && i % 2 == 1*/) {
                newDiff[ypos - 1] = 0;
                ypos--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sum += newDiff[i];
    }
    for (int i = 0; i < n; i++) {
        cout << differ[i] << " //  " << newDiff[i] << endl;
    }
    cout << "sum is " << sum << endl;
    if (sum > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int j = 0; j < T; j++) {
        int n = 0, t = 0;
        cin >> n >> t;
        solve(n, t);
    }
}
