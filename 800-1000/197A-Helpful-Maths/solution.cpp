#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt[4]={};
    for(auto ch:s){
        if(ch!='+'){
            cnt[ch-'0']++;
        }
    }
    
    bool first=true;
    for(int i=1;i<=3;i++){
        for(int j=0;j<cnt[i];j++){
            if(!first) cout<<"+"<<i;
            else{
                cout<<i;
                first=false;
            }
        }
    }
    return 0;
}