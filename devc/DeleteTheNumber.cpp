#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
        for (int i = 1; i < str.length() + 1; i++) {
            if (str[i - 1] > str[i]) {
                str.erase(i - 1, 1);
                // cout << str << endl;
                break;
            }
        }
    }
    if(str.empty()){
        cout<<"0";
        return 0;
    }
    cout << str;
}