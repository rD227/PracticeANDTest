#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;
        vector<int> v(n);
        /*upper seeped*/
        int sum = 0;
        int average;
        for (int j = 0; j < n; j++) {
            cin >> v.at(j);
        }
        for (int k = 0; k < n; k++) {
            sum += v.at(k);
        }
        average = sum / n;
        for (int j = 0; j < n; j++) {
            if (v.at(j) <= average) {
                for (int k = 0; k < j; k++) { // traversal from front
                    if (v.at(k) > v.at(j)) {
                        +canFromFront = flase;
                    }
                }
            }
        }
    }
}