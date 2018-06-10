class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int ans;
        int l,r;
        int min_width = 10000000;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
            int tar = target - nums[i];
            l = i+1;
            r = size-1;
            while(l<r)
            {
                if(abs(nums[l]+nums[r]-tar)<min_width) 
                {
                    ans  = nums[l]+nums[r]+nums[i];
                    min_width = abs(nums[l] + nums[r]-tar); 
                }
                if(nums[l]+nums[r]>tar) r--;
                else if(nums[l]+nums[r]<tar) l++;
                else 
                {
                    ans  = target;
                    min_width = 0;
                    break;
                }
               
            }
        }
        return ans;
    }
};
