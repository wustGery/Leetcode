class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int cnt = height.size();
        int max_water = -1;
        int l = 0,r = cnt-1;
        while(l<r)
        {
            int temp = min(height[r],height[l])*(r-l);
            if(temp>max_water)  max_water = temp;
            if(height[r]<height[l])  r--;
            else l++;
        }
        return max_water;
    }
};

