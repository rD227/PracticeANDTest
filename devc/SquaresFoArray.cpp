#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> dp(n, vector<int>(n, 0));

void draw(int initx, int inity, int length) {
    if (length == 1) {
        dp[inity][initx] = 1;
        // dp.at(initx)(inity)=1;
        return;
        // 我也不知道要做什么；
    }
    draw(initx, inity, length / 2);
    draw(initx - length / 2, inity - length / 2, length / 2);
    draw(initx - length / 2, inity, length / 2);
}
int main() {
    cin >> n;
    int squ = (int)pow(2, n);
    dp.assign(squ, vector<int>(squ, 0));
    // cout << "@" << endl;
    draw(squ - 1, squ - 1, squ);
    // cout << squ;
    // cout << "**" << endl;
    for (int i = 0; i < squ; i++) {
        for (int j = 0; j < squ; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}