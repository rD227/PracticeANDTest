#include <bits/stdc++.h>

using namespace std;

/*void sovle(int k, int n) {
    int count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());//4 2 /1 4 3 4-->should be 0 1 3 4
    for (int i = 0; i < n; i++) {//but it just rember the same words
        cout << v.at(i) << "// ";//we can  sort it
        if (v.at(i) == k) {//then it turn into 1 3 4 4
            count++;//left to right, didn't find the 0(first natrue number)
        }else//we need change the array,LTR,turn 1 into 0,turn 3 to 1: 0 1 4 4
    }//use twice times
    cout << "the count is " << count << endl;
}*/
bool isMexAlreadyEqualToA(vector<int> v, int k) { // 传入排序过后的
    bool ans = false;
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == k) {
            return false;
        }
    }
}
void changedSovle(int n, int k) {
    int count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < n; j++) {
        if (v.at(i) != j && j != k) {

        } else if (v.at(i) == k) {
            v.at(i)
        }
    }
}
int main() {
    int t, k, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        sovle(k, n);
    }
}