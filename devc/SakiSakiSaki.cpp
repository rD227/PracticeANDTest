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
            if (x % 2 == 0) {
                evenSum += x;
                evenNum++;
            } else {
                oddSum += x;
                oddNum++;
            }
        }
        cout << "***" << oddNum << "&&" << evenNum;
        if ((oddSum / oddNum) == (evenSum / evenNum)) {
            canBeDivise = true;
        }
        if (sum % n == 0 && canBeDivise) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}