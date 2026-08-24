#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> heights(n,0);
    int maxSecWatered=-1;
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    for(int i=0;i<n;i++){
        int left=i-1,right=i+1;
        int cnt=1;
        int currHeight=heights[i];
        while(left>=0){
            if(heights[left]<=currHeight){
                cnt++;
                currHeight=heights[left];
            }
            else break;
            left--;
        }
        currHeight=heights[i];
        while(right<n){
            if(heights[right]<=currHeight){
                cnt++;
                currHeight=heights[right];
            }
            else break;
            right++;
        }
        maxSecWatered=max(maxSecWatered,cnt);
    }
    cout<<maxSecWatered;
    return 0;
}