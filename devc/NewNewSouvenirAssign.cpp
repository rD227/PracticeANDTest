#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    int i = 0, j = n - 1, count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        // cout << v.at(i) << "//" << endl;
    }
    while (i <= j) {
        if (v.at(i) + v.at(j) <= w) {
            i++;
            j--;
            count++;
            // cout << "i is " << i << " j = " << j << endl;
        } else {
            j--;
            count++;
            // cout << "j = " << j << endl;
        }
    }
    cout << count << endl;
}