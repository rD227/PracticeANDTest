#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int sum = 0;
        int oddSum = 0, evenSum = 0;
        int oddNum = 0, evenNum = 0;
        int x;
        bool canBeDivise = false;
        for (int j = 0; j < n; j++) {
            cin >> x;
            sum += x;
            if ((j + 1) % 2 == 0) { // 应该不需要判断其奇偶位平均数？
                evenSum += x;
                evenNum++;
            } else {
                oddSum += x;
                oddNum++;
            }
        }

        if ((oddSum / oddNum == sum / n) && (evenSum / evenNum == sum / n)) {
            canBeDivise = true; // 判断奇偶位平均数
        }
        if (sum % n == 0 && canBeDivise) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}