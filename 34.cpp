class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int>ans;
        if(nums.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int first_index,second_index;
        first_index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(first_index==nums.size()||nums[first_index]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(first_index);
            second_index = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            if(nums[second_index-1]!=target)  ans.push_back(-1);
            else ans.push_back(second_index-1);
        }
        return ans;
    }
};
