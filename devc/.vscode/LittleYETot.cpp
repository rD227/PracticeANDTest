#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ans.at(i) == i + 1;
    } // deserved
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<vector<int>> div;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v.at(i); j++) {
            int x;
            cin >> x;
            div[i].push_back(x);
        }
    }
}

int main() {}