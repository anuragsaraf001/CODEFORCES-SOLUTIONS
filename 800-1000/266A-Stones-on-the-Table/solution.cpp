#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; //number of stones on the table
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            cnt++; //since two adjacent are same therefore we have to remove this stone
        }
    }
    cout<<cnt<<endl;
    return 0;
}