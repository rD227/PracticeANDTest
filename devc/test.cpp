#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T, k;
    cin >> T;
    for (int j = 0; j < T; j++) {
        cin >> n >> k;
        int cnt = 0;
        vector<int> yy(n, 0);
        for (int i = 0; i < n; i++) {
            int S = 0;
            cnt = 0;
            cin >> yy[i];
            if (yy[i] >= k) {
                S += yy[i];
                cout << "yy is" << yy[i] << "S is " << S << endl;
            } else if (yy[i] == 0 && S >= 1) {
                S = S - 1;
                cnt += 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}