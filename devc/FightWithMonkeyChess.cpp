#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    int n1 = -1, n2 = -1;
    string animals[] = {"elephant", "tiger", "cat", "mouse"};
    cin >> s1 >> s2;
    for (int i = 0; i < 4; i++) {
        if (s1 == animals[i]) {
            n1 = i;
        }
        if (s2 == animals[i]) {
            n2 = i;
        }
    }
    cout << n1 << " " << n2 << endl;
    // for (int i = 0; i < 4; i++) {
    if (n2 == 3 && n1 == 0) {
        cout << "lose";
        return 0;
    }
    if (n1 == 3 && n2 == 0) {
        cout << "win";
        return 0;
    }
    if (n1 > n2) {
        cout << "lose";
        return 0;
    }
    if (n1 < n2) {
        cout << "win";
        return 0;
    }
    if (n2 == n1) {
        cout << "tie";
        return 0;
    } else {
        cerr << " OOOPS! HERE IS SOMETING WORONG!!";
        return -1;
    }
    //}
}