#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int prev=-1;
    int cnt=0;
    int maxCnt=INT_MIN;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>prev){
            cnt++;
            maxCnt=max(cnt,maxCnt);
            prev=a;
        }
        else{
            cnt=1;
            prev=a;
        }
    }
    cout<<maxCnt<<"\n";
    return 0;
}