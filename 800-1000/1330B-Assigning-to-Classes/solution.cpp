#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(2*n,0);
        for(int i=0;i<2*n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        cout<<arr[n]-arr[n-1]<<endl;
    }
    return 0;
}