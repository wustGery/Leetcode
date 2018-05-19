class Solution {
public:
    bool isMatch(string s, string p)
    {
        int dp[s.length()+1][p.length()+1];
        int l1 = s.length();
        int l2 = p.length();
        memset(dp,0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=0;i<l1;i++) dp[i+1][0] = 0;
        for(int j=0;j<l2;j++) dp[0][j+1] = j>0&&dp[0][j-1]&&p[j]=='*';
        for(int i=0;i<l1;i++)
            for(int j=0;j<l2;j++)
            {
                if(p[j]!='*') dp[i+1][j+1] = dp[i][j]&&(s[i]==p[j]||p[j]=='.');
                else
                    dp[i+1][j+1] = j>0&&dp[i+1][j-1] || dp[i+1][j] || j>0&&dp[i][j+1]&&(p[j-1]=='.'||p[j-1]==s[i]);
            }
        return dp[l1][l2];
    }

};
