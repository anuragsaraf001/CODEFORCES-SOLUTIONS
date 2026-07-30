#include <bits/stdc++.h>
using namespace std;

void dragons(int s,vector<pair<int,int>> &power){
    for(auto it:power){
        if(s<=it.first){
            cout<<"NO";
            return;
        }
        s+=it.second;
    }
    cout<<"YES"; 
}

int main()
{
    int s,n;
    cin>>s>>n;
    vector<pair<int,int>> power;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        power.push_back({x,y});
    }
    sort(power.begin(),power.end());
    dragons(s,power);
    return 0;
}