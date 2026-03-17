#include <bits/stdc++.h>

using namespace std;

unsigned long long factorial(int n) {
    unsigned long long sum = 1;
    for (int i = 0; i < n; i++) {
        sum = sum * (i + 1);
    }
    return sum;
}

unsigned long long factor(int begin, int end) {
    unsigned long long sum = 1;
    for (int i = end + 1; i < begin; i++) {
        sum = sum * i;
        //
        cout << "[" << sum << "]"; //
    }
    //
    cout << "{" << sum << "}"; // test
    return sum;
}

unsigned long long assign(int up, int down) {
    unsigned long long ans = -1;
    if (up < down) {
        ans = factor(down, up);
        cout << "down is " << down << " up is " << up << "**" << endl; // test
    } else { // 应该没用这个
        ans = factorial(down) / (factorial(up) * factorial(abs(down - up)));
    }
    return ans;
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                cout << "1" << " ";
            } else {
                cout << assign(j, i) << " ";
            }
            // ut << i << " ";
        }
        cout << "//" << endl;
    }
}

int main() {
    // factor(3,2);
    int n;
    cin >> n;
    print(n);
}
