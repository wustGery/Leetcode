class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.empty())  return 0;
        int size = height.size();
        int ans = 0;
        vector<int> max_left(size),max_right(size);
        max_left[0]  = height[0];
        for(int i=1;i<size;i++)  max_left[i] = max(max_left[i-1],height[i]);
        max_right[size-1]  =  height[size-1];
        for(int i=size-2;i>=0;i--)  max_right[i]  = max(max_right[i+1],height[i]);
        for(int i=1;i<size-1;i++) ans += (min(max_left[i],max_right[i])-height[i]);
        return ans;
    }
};
