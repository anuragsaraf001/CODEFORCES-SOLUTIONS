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
    int cntA=0,cntD=0;
    for(auto it:s){ 
        if(it=='A') cntA++;
        else cntD++;        
    }
    if(cntA==cntD){
        cout<<"Friendship";
        return 0;
    }
    (cntA>cntD)? cout<<"Anton" : cout<<"Danik" ;
    return 0;
}