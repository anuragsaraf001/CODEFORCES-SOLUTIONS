#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> mat(n);
        for(int i=0;i<n;i++){
            cin>>mat[i];
        }
        //check only the last row and the last col
        int cnt=0;
        for(int j=0;j<m-1;j++){
            if(mat[n-1][j]=='D') cnt++;
        }
        for(int i=0;i<n-1;i++){
            if(mat[i][m-1]=='R') cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}