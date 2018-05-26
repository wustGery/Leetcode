class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.empty()) return 0;
        int size = height.size();
        int left_max,right_max;
        left_max = right_max = 0;
        int left = 0,right = size-1;
        int ans = 0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>left_max) left_max = height[left];
                else ans += left_max-height[left];
                left++;
            }
            else 
            {
                if(height[right]>right_max)  right_max = height[right];
                else ans += right_max-height[right];
                right--;
            }
        }
        return ans;
    }
};
