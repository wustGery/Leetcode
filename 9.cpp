class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        stack<int>st;
        queue<int>qu;
        if(x<0) return false;
        else if(x==0) return true;
        else 
        {
            int temp = x;
            while(temp)
            {
                int val = temp%10;
                st.push(val);
                qu.push(val);
                temp/=10;
            }
        }
        bool flag = true;
        while(!st.empty())
        {
            int x=  st.top();
            int y = qu.front();
            if(x!=y)  
            {
                flag  = false;
                break;
            }
            st.pop();
            qu.pop();
        }
        return flag;
    }
    
};
