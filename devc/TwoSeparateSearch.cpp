#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int getlowerAndTheSame(int mid) {
    while (mid != 0 && v.at(mid - 1) == v.at(mid)) {
        mid--;
    }
    return mid;
}

void solve(int y, int n) {
    int begin = 0, end = v.size() - 1;
    int ans = -1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        // cout << begin << "       " << mid << "         " << end << endl;
        if (v.at(mid) == y) {
            ans = mid;
            if (mid == 0) {
                cout << mid + 1 << " ";
                return;
            }
            if (y == v.at(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                cout << mid + 1 << " ";
                return;
            }
        } else if (v.at(mid) < y) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (ans == -1) {
        cout << ans << " ";
    } else {
        cout << ans + 1 << " ";
    }
    // cout << -1 << "
    // ";//其实应该前面不return，在后面判断ans是否等于-1，再cout>>ans
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        solve(y, n);
    }
}