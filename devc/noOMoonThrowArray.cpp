#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> v.at(j);
        }
        // for(int k=0;k<n;k++){
        vector<int> frontAndBack(n, 0);
        int val_max = INT_MIN;
        int val_min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (v.at(j) < val_min) {
                val_min = v.at(j);
                frontAndBack.at(j) = 1;
            }
            /*if(v.at(j)>val_max){
                val_max=v.at(j);*/
            // for(int k=0;k<n;k++){
            // }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (v.at(j) > val_max) {
                val_max = v.at(j);
                frontAndBack.at(j) = 1;
            }
        }
        for (int out = 0; out < n; out++) {
            cout << frontAndBack[out] << " ";
        }
        /*while (n--) {
            cout << frontAndBack[n] << " ";
            //}
            cout << endl;
        }*/
    }
}