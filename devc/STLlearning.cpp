#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> imap;
    for (int i = 0; i < 5; i++) {
        i++;
        imap[i] = i;
        cout << "imap[" << i << "]" << "=" << imap[i] << endl;
    }
    for (auto [key, value] : imap){
        cout << key << ": " << value << endl;
    }
}