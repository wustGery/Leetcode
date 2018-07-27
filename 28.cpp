class Solution
{
public:
    void getNext(string p,int *next)
    {
        int p_len = p.length();
        int j,k;
        next[0] = -1;
        j = 0;
        k = -1;
        while(j<p_len-1)
        {
            if(k==-1||p[k]==p[j])  next[++j] = ++k;
            else k = next[k];
        }
    }

    int KMP(string s,string p,int *next)
    {
        int i,j;
        i = j = 0;
        int s_len = s.length();
        int p_len = p.length();
        while(i<s_len&&j<p_len)
        {
            if(j==-1||s[i]==p[j])
            {
                ++i;
                ++j;
            }
            else j = next[j];
        }
        return j==p_len?i-j:-1;
    }


    int strStr(string haystack, string needle)
    {
        int needle_len = needle.length();
        int *next = new int[needle_len];
        getNext(needle,next);
        int ans = KMP(haystack,needle,next);
        return ans;
    }
};
