#include <bits/stdc++.h>

using namespace std;

int hasOne(int num, int n) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == n) {
            count += 1;
            /*cout << "I count " << count << "the num" << num << "//";*/
        }
        num /= 10;
    }
    return count;
}

int main() {
    int n, theReferNumber;
    int sum = 0;
    cin >> n >> theReferNumber;
    for (int i = 0; i < n; i++) {
        sum += hasOne(i + 1, theReferNumber);
        /*cout << "i is " << i << " theReferNumber is" << theReferNumber <<
         * endl;*/
    }
    cout << sum << endl;
    // cout << "sum is " << sum << endl;
    // cout << "******" << endl;
}