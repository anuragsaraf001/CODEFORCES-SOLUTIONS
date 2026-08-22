#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string table;
    cin>>table;
    bool ans=false;
    for(int i=0;i<5;i++){
        string hand;
        cin>>hand;
        if(hand[0]==table[0] || hand[1]==table[1]) ans=true;
    }
    (ans) ? cout<<"YES" : cout<<"NO";
    return 0;
}