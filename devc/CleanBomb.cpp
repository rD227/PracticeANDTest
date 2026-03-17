#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> vc(n + 2, vector<char>(m + 2));
    vector<vector<char>> copyvc;
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                vc[i][j] = '.';
            } else {
                char x;
                cin >> x;
                vc[i][j] = x;
            }
        }
    }
    copyvc = vc;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int x = 0;
            for (int k = i - 1; k < i + 2; k++) {
                for (int p = j - 1; p < j + 2; p++) {
                    if (!(k == i && p == j)) {
                        if (vc[k][p] == '*') {
                            x = x + 1;
                        }
                    }
                }
            }
            // cout << x << endl;
            if (copyvc[i][j] != '*') {
                copyvc[i][j] = x + '0';
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int k = 1; k < m + 1; k++) {
            cout << copyvc[i][k];
        }
        cout << endl;
    }
}