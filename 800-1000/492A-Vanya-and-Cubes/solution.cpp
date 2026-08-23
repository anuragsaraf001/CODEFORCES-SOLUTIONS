#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i=1;
    int noPy=0;
    while(noPy+(i*(i+1))/2<=n){
        noPy+=(i*(i+1))/2;
        i++;
    }
    cout<<i-1<<endl;
    return 0;
}