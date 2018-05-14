class Solution {
public:
    string longestPalindrome(string s)
    {
        int l,r,max_length=1;
        int dp[1000+10][1000+10];
        memset(dp,0,sizeof(dp));
        int len = s.length();
        for(int i=0;i<len;i++)  dp[i][i] = 1;
        for(int i=0;i<len-1;i++)
        {
            if(s[i]==s[i+1])
            {
                l = i;
                r = i+1;
                max_length =2 ;
                dp[i][i+1] = 2;
            }
        }
        int left=0,right=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]==s[i+1]&&i+1<len)longestPalindrome
            {
                left = i-1;
                right = i+2;
                while(left>=0&&right<len&&s[left]==s[right])
                {
                    dp[left][right] = dp[left+1][right-1]+2;
                    if(dp[left][right]>max_length)
                    {
                        l = left;
                        r = right;
                        max_length = dp[left][right];
                    }
                    left--;
                    right++;
                }
            }
            if(s[i-1]==s[i+1]&&i+1<len&&i-1>=0)
            {
                left = i-1;
                right = i+1;
                while(left>=0&&right<len&&s[left]==s[right])
                {
                    dp[left][right] = dp[left+1][right-1]+2;
                    if(dp[left][right]>max_length)
                    {
                        l = left;
                        r = right;
                        max_length = dp[left][right];
                    }
                    left--;
                    right++;
                }
            }
        }
        string ans;
        if(max_length==1)  ans.push_back(s[0]);
        else
            for(int i=l;i<=r;i++) ans.push_back(s[i]);
        return ans;
    }
};
