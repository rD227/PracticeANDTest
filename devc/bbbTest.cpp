#include <bits/stdc++.h>

using namespace std;

int minSteps(long long x, long long y) {
    long long determin = abs(y - x);
    if (determin == 1) {
        return -1;
    }
    long long q = determin / 3, r = determin % 3; // biger step is better
    if (r == 0) {
        return q;
    } else if (r == 2) {
        return q + 1;
    } else {
        if (determin >= 4) {
            return q + 1;
        } else
            return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x, y;
    cin >> x >> y;
    cout << minSteps(x, y) << "\n";
    return 0;
}
