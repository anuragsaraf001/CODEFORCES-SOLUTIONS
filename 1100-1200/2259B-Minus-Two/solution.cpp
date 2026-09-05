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
        vector<int> arr(n,0);
        map<int,int> mpp;
        int oddCnt=0,cntMod0=0,cntMod2=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2!=0) oddCnt++;
            else{
                if(arr[i]%4==2) cntMod2++;
                else cntMod0++;
            }
            mpp[arr[i]]++;
        }
        int ans=INT_MIN;
        for(auto it: mpp){
            ans=max(ans,it.second);
        }
        cout<<max(ans,max(cntMod0,max(cntMod2,oddCnt)))<<endl;
    }
    return 0;
}