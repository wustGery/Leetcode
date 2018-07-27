class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size()==0)  return 0;
        vector<int>::iterator iter = nums.begin();
        int pre_value = *iter;
        ++iter;
        for(;iter!=nums.end();)
        {
            int value = *iter;
            if(value==pre_value)
                nums.erase(iter);
            else
            {
                pre_value = value;
                ++iter;
            }
        }
        return nums.size();
    }

};
