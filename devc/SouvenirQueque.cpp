#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, n;
    int ans = 0;
    cin >> w >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) { // 遍历每一个数组当中的成员
        int pos = -1;
        for (
            int j = i; j < n;
            j++) { // 从这个成员向后遍历成员，保证每个成员都和另外一个进行一对一比较
            int needMaxOfBehind = w - v.at(i);
            int temp = 0; // 记录当前所获得的最大的值
            if (v.at(j) <= needMaxOfBehind &&
                temp < v.at(j)) { // 尽量找到小于这个范围的最大的数；
                needMaxOfBehind = v.at(j);
                temp = v.at(j);
                pos = j;
                continue;
            }
            // j==n-1&&v.at(j)!=needMaxOfBehind
        } // 遍历完毕，找到所需最大成员或者没有找到
        if (pos != -1 &&
            v.at(i) + v.at(pos) <= w) { // 短路运算符，如果没有找到就直接跳过
            ans++;                      // if的第二条要求可能用不到...
            v.at(i) = INT_MAX;          // 记录找到配偶的为intmax
            v.at(pos) = INT_MAX;
            continue;
        }
    }
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " << endl;
        if (v.at(j) != INT_MAX) {
            ans++;
        }
    }
    cout << ans << endl;
}