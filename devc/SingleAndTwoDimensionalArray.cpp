#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum;
}