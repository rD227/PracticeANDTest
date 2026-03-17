#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 1));
    int i = 0, j = 0;
    bool solve = true;
    // vector<vector<int>> v;
    /*for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }*///AI给的push_back版本，不需要指定初始大小（push_back会完成）;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << "*";
        }
        cout << endl;
    }*/
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < a; b++) {
            if (v[a][b] != 0) {
                solve = false;
            }
            // v[a][b] = 9;
            //  cout << "#";
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
    if (solve) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}