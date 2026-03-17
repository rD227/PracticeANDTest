#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    string s0 = "swiper";
    cin >> s;
    int ans;
    int k = 0;
    bool loop = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s0[0] && loop) {
            ans = i;
            k++;
            loop = 0;
            // cout << "ans is " << ans << endl;
        }
        if (s[i] == s0[k] && k != 0) {
            k++;
            // cout << "ANS is " << ans << endl;
        }
    }
    if (k == 6) {
        cout << ans << endl;
    } else {
        cout << -1;
    }
    // cout << ans;
}