class Solution {
public:
    int trap(vector<int>& height) 
    {
        stack<int>st;
        int ans = 0;
        int size = height.size();
        int cur = 0;
        while(cur<size)
        {
            while(!st.empty()&&height[cur]>height[st.top()])
            {    
                int top = st.top();
                st.pop();
                if(st.empty())  break;
                int distance = cur - st.top() -1 ;
                int h = min(height[cur],height[st.top()]) - height[top];
                ans  += h * distance;
            }
            st.push(cur++);
        }
        return ans;
    }
};
