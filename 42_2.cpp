class Solution {
public:
    int trap(vector<int>& height)
    {
        int size = height.size();
        int ans = 0;
        int max_left,max_right;
        for(int i=1;i<size-1;i++)
        {
            max_left = 0,max_right = 0;
            for(int j=i;j>=0;j--)
                max_left = max(max_left,height[j]);
            for(int j=i;j<size;j++)
                max_right = max(max_right,height[j]);
            ans += (min(max_left,max_right) - height[i]);
        }
        return ans;
    }
};
