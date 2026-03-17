#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int MYlower_bound(int begin,int end,int mid){

}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> vc;
    for(int i=0;i<m;i++){
        int y;
        cin>>y;
        vc.push_back(y);
    }
    int begin=0,end=v.size()-1;
    int mid=(begin+end)/2;
    for(int i=0;i<m;i++){
        if(begin<=end){
            mid=(end+begin)/2;
            if(v.at(mid)==vc.at(i)){
                cout<<mid<<" ";
                break;
            }else if(v.at(mid)<vc.at(i)){
                begin=mid+1;
            }else{
                end=mid-1;
            }
        }else{
            cout<<-1<<" ";
        }
    }
}