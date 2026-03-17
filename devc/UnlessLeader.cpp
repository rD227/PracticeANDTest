#include <bits/stdc++.h>
using namespace std;

long long fast_pow(int a, int b, int m) {
    long long result = 1;
    a %= m; // 先对 a 取模，避免溢出
    while (b > 0) {
        if (b & 1) { // 如果 b 的最低位是 1
            result = (result * a) % m;
        }
        a = (a * a) % m; // a 自乘
        b >>= 1;         // b 右移一位
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    int a, b;
    // long long sqareDifference;
    // for (int k = 0; k < t; k++) {
    // cin >> a >> b;
    // sqareDifference = (abs(a * a - b * b));
    // while (t--) {
    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;
        long long d = abs(a * a - b * b);
        long long k = (d / 2) - 1;
        if (d >= 8) {
            k += ((d - 1) / 4) - 1;
        }
        cout << k + 1 << endl;
    }
    // cout << sqareDifference << "***" << endl;
    //  int i = -1;
    /*if (sqareDifference % 2 == 0) {
        cout << "**";
        cout << ((sqareDifference / 4) + 1) << endl;
        continue;
    } else {
        for (int count = 1; count <= sqareDifference / 2; count++) {
            cout << "#"<<count;
            if (sqareDifference == 3) {
                cout << 1 << endl;
                break;
            }
            if (sqareDifference / 2 == count ||
                sqareDifference / 2 == count - 1) {
                cout << count  << endl;
                break;
            }
        }
    }*/
    //}
}