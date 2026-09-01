#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=1; //no of chars
    int j=0; //idx
    string ans="";
    while(j<n){
        ans+=s[j];
        j+=i;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}