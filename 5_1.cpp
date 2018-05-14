class Solution {
public:
    string longestPalindrome(string s)
    {
        int l=0,r=0,max_length = 1;
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        int len = s.length();
        for(int i=0;i<len;i++)  dp[i][i] = 1;
        for(int i=0;i<len;i++)
            for(int j=0;j<i;j++)
            {
                if(i-1>=0) dp[j][i] = (s[i]==s[j]&&(i-j<2||dp[j+1][i-1]));
                if(dp[j][i]&&i-j+1>max_length)
                {
                    l = j;
                    r = i;
                    max_length = i-j+1;
                }
            }
        string ans;
        for(int i=l;i<=r;i++)  ans.push_back(s[i]);
        return ans;
    }
};
