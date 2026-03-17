#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> ans;
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        ans.push_back(y);
        for(int j=0;j<n;j++){
            if(v.at(j)==y){
                cout<<"v.at(j)== "<<v.at(j)<<" && y=="<<y<<endl;
                ans[i]=j+1;
                break;
            }
            ans[i]=-1;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans.at(i)<<" ";
    }
}