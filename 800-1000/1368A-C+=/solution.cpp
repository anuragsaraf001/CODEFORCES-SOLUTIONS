#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,n;
        cin>>a>>b>>n;
        int op=0;
        while(a<=n  && b<=n){
            op++;
            if(a<=b) a+=b;
            else b+=a;
        }
        cout<<op<<endl;
    }
    return 0;
}