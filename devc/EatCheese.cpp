#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

double x[20], y[20];
double dp[1 << 20][20];
double dista[20][20];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    } // preprocessing:make reserved distance
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            dista[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
    int max_mask = 1 << n;
    for (int mask = 0; mask < max_mask; mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = 1e18;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    for (int mask = 0; mask < max_mask; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)))
                continue;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (!(mask & (1 << j)))
                    continue;
                int prev_mask = mask ^ (1 << i);
                dp[mask][i] = min(dp[mask][i], dp[prev_mask][j] + dista[j][i]);
            }
        }
    }
    double ans = 1e18;
    int full = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[full][i]);
    }
    printf("%.2f\n", ans);
    return 0;
}
