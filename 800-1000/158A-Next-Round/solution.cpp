#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int cutoff=arr[k-1];
    int cnt=0;
    for(auto it:arr){
        if(it>=cutoff && it>0) cnt++;
    }
    cout<<cnt;
    return 0;
}