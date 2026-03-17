#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

void slove(int n){
    vector<string> nums;
    while(n--){
        string x;
        cin>>x;
        nums.push_back(x);
    }
    /*
        for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            int temp= 0;
            string tempans = "";
            for(int k=i;k<nums.size();k++){
                tempans+=nums[k];
            }
            temp=stoi(tempans);
            if(stoi(nums[i])>int_max){
                int_max=temp;
            }else{
                string change = nums[j];
                nums[j]=nums[i];
                nums[i]=change;
            }
        }
    }
    cout<<int_max<<"\n";
}
    */
    sort(nums.begin(), nums.end(), cmp);

    if (nums[0] == "0") {
        cout << "0\n";
        return;
    }

    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    slove(n);
    return 0;
}