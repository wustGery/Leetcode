class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> >vec;
        if(nums.size()==0)  return vec;
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int l,r;
        for(int i=0;i<size;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int ans = -nums[i];
            l = i+1;
            r = size-1;
            while(l<r)
            {
                int _2sum = nums[l]+nums[r];
                if(_2sum>ans) r--;
                else if(_2sum<ans) l++;
                else 
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    vec.push_back(temp);
                    l++;
                }
            }
        }
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        return vec;
    }
};
