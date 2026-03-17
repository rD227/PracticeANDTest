#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    int ans = -1;
    vector<int> v;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); i++) {
        // cout << i << "not bteak%%" << endl;
        // cout << v.at(i) << " && x = " << x << endl;
        if (v.at(i) == x) {
            ans = i + 1;
            // cout << ans << endl;
            break;
        }
    }
    cout << ans;
}