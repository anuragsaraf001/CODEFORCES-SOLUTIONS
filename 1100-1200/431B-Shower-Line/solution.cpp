#include <bits/stdc++.h>
using namespace std;

void showerLine(vector<vector<int>> &matrix){
    int maxHap=-1;
    vector<int> nums={0,1,2,3,4};
    do {
        int sum=0;
        sum=(matrix[nums[0]][nums[1]]+matrix[nums[1]][nums[0]]+matrix[nums[2]][nums[3]]+matrix[nums[3]][nums[2]])+(matrix[nums[1]][nums[2]]+matrix[nums[2]][nums[1]]+matrix[nums[3]][nums[4]]+matrix[nums[4]][nums[3]])+(matrix[nums[2]][nums[3]]+matrix[nums[3]][nums[2]])+(matrix[nums[3]][nums[4]]+matrix[nums[4]][nums[3]]);
        maxHap=max(maxHap,sum);
    }
    while(next_permutation(nums.begin(),nums.end())); 
    cout<<maxHap<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> matrix(5,vector<int> (5,0));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
        }
    }
    showerLine(matrix);
    return 0;
}