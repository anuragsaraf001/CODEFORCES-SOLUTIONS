#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x;
    cin>>x;
    int steps=0;
    for(int i=5;i>=1;i--){
        if(x==0){
            cout<<steps;
            return 0;
        }
        steps+=x/i;
        x=x%i;
    }
    cout<<steps;
    return 0;
    return 0;
}