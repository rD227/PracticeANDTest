#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> pp(n, 78);
    // auto it = pp.begin();
    for (int i = 0; i < n; i++) {
        pp[i] = i;
        // cout << pp[i] << endl;
    }
    // it = pp.begin() + k;
    int pos = k;
    while (pp.size() > 1) {
        // pos = (pos + k - m);
        pos = (pos + m - 1) % pp.size();
        if (pos < 0)
            pos += pp.size();
        pp.erase(pp.begin() + pos);
        if (pos == pp.size())
            pos = 0;
        // cout << "Now it is " << pp[0] << endl;
    }
    /* while (pp.size() > 1) {
         int pos = (pos + k - m) % pp.size();
         if (it == pp.end()) {
             it = pp.begin(); // 回到头部，避免越界
         }
         it = pp.erase(it);
         if (it == pp.end()) {
             it = pp.begin(); // 回到头部，避免越界
         }
         // cout << "Now  it is " << *it << endl;
     }*/
    cout << pp[0];
}