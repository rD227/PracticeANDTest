#include <bits/stdc++.h>

using namespace std;

int main() {
    long long initialSail = 1000;
    long long initialYueChan = 1000;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, t;
        long long sumOfs = 0, sumOfy = 0;
        cin >> n >> t;
        vector<int> vs;
        // vector<int> souldRemoveOfs;
        vector<int> vy;
        // vector<int> souldRemoveOfv;
        // int maxOfs = INT_MIN, maxOfy = INT_MIN;
        // int shouldRemoveOfs=-1,shouldRemoveOfy=-1;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            vs.push_back(x);
        }
        // 进行排序
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n - 1; j++) {
                if (vs[j] < vs[j + 1]) {
                    int temp = vs[j];
                    vs[j] = vs[j + 1];
                    vs[j + 1] = temp;
                }
            }
        }
        // t似乎可能等于0
        for (int j = 0; j < t; j++) {
            vs.at(j) = 0;
        }
        for (int j = 0; j < n; j++) { // test
            cout << vs[j] << "%%";
        }
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            vy.push_back(x);
        }
        // 44
        cout << "iii" << sumOfs << endl;
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n - 1; j++) {
                if (vy.at(j) < vy.at(j + 1)) {
                    int temp = vy.at(j);
                    vy.at(j) = vy.at(j + 1);
                    vy.at(j + 1) = temp;
                }
            }
        }
        for (int j = 0; j < t; j++) {
            vy.at(j) = 0;
        }
        for (int j = 0; j < n; j++) {
            sumOfy += vy.at(j);
        }
        // cout << "sumOfs is " << sumOfs << " sumOfy is " << sumOfy << endl;
        if (sumOfs > sumOfy) {
            cout << "##YES" << endl;
        } else {
            cout << "##NO" << endl;
        }
    }
}