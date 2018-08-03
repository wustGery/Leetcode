#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int k,l;
    int len = nums.size();
    k = len-1;
    while(k>=0)
    {
        if(nums[k]>nums[k-1])
        {
            k = k-1;
            break;
        }
        k--;
    }
    if(k==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }
    for(l=len-1;l>k;l--)
        if(nums[l]>nums[k]) break;
    cout<<l<<" "<<k<<endl;
    swap(nums[k],nums[l]);
    reverse(nums.begin()+(k+1),nums.end());
}


int main()
{
    initializer_list<int> lst = {1,3,2};
    vector<int>nums(lst);
    nextPermutation(nums);
    for(int i=0;i<nums.size();i++)  cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
