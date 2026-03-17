#include <bits/stdc++.h>

using namespace std;

int howManyFour(string s) {
    int n = s.size();
    int count = 0;
    while (n >= 4) {
        n /= 4;
        count++;
        /* code */
    }
    // cout << "**" << count << endl;
    return count + 1;
}

int main() {
    string str;
    cin >> str;
    string sout;
    int start = 0;
    string strarr[] = {"",   "wan",  "yi",  "zhao", "jing",  "gai",
                       "zi", "rang", "gou", "jian", "zheng", "zai"};
    // string strarr[] = {"zai", "zheng", "jian", "gou", "rang", "zi",
    //                    "gai", "jing",  "zhao", "yi",  "wan",  ""};
    bool loop = true;
    bool fuckBug = true;
    int k = howManyFour(str) + 1;
    for (int i = 0; i < (str.size() + 3) / 4; i++) {
        /*cerr << "start=" << start << " k=" << k
             << " substr=" << str.substr(start, min(4, (int)str.size() - start))
             << endl;*/
        cout << k << " " << start << endl;
        if (start <= str.size()) {
            if ((str.size() % 4) != 4 && fuckBug) {
                sout += str.substr(0, (str.size() % 4));
                fuckBug = false;
                sout += strarr[k];
                k -= 1;
                start += 4;
                /*cerr << "start=" << start << " k=" << k << " substr="
                     << str.substr(start, min(4, (int)str.size() - start))
                     << endl;*/
                cerr << k << " " << start << endl;
            }
            if (!fuckBug) {
                start = str.size() % 4;
            }
            sout += str.substr(start, 4);
            sout += strarr[k];
            k -= 1;
            start += 4;
        }
        if (loop == true && str.size() / 4 == 0) {
            sout += strarr[i];
        }
        if (str[i / 4 - 1] == 0) {
            loop = false;
            continue;
        }
    }
    // for (int i = 0; i < str.size() / 4; i++) {

    //}
    cout << sout << endl;
    // cout << howManyFour("7827837833889889") << endl;
}