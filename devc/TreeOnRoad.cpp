#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    vector<int> v(l + 1, 1);
    for (int i = 0; i < m; i++) {
        int Ii, Ri;
        cin >> Ii >> Ri;
        fill(v.begin() + Ii, v.begin() + Ri, 0);
    }
    int count = 0;
    /*for (int i = 0; i < l; i++) {
        cout << "$$" << v[i] << endl;
    }*/
    for (int i = 0; i < l; i++) {
        if (v[i] == 1) {
            count++;
        }
    }
    cout << count << endl;
}