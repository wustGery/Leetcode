class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int ans = -1;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(nums[mid]==target)   return mid;
            else if(nums[mid]<target) l = mid+1;
            else r = mid-1;
        }
        return l;
    }
};
