#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n;
    int ans = 0;
    cin >> w >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v.at(i) << "//";
    }
    cout << endl;
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = n / 2 - 1; j < n; j++) {
                if (v.at(i) + v.at(j) <= w) {
                    ans++;
                } else {
                    ans += 2;
                }
            }
        }
    } else if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (v.at(i) + v.at(j) > 100) {
                    j--;
                    if (j = i) {
                        ans++;
                    } else {
                        ans++;
                    }
                } else {
                }
            }
            int i = 0, j = n - 1;
            while (true) {
                if (v.at(i) + v.at(j) > 100) {
                    j--;
                    if (j = i) {
                        ans++;
                    }
                } else {
                    ans++;
                }
            }
            for (int i = 0; i <= n / 2; i++) {
                if (i == n / 2) {
                    ans++;
                    break;
                }
                for (int j = n - 1; j >= n / 2; j--) {
                    if (v.at(i) + v.at(j) <= w) {
                        ans++;
                        break;
                    } else {
                        ans += 2;
                        break;
                    }
                }
                /*if (v.at(i) + v.at(n - i - 1) <= w) {
                    ans ++;
                } else {
                    ans += 2;
                }*/
            }
        }
        cout << ans;
    }