/*题解 
    m永远表示最近的一个没有重复的字符的下标
    用L[i] = s[m...i],当出现第s[i+1]字符的时候
    则会出现两种情况，若s[i+1]不是在s[m..i]中出现的则L[i+1] = s[m...i+1]
    若s[i+1]出现在s[m...i]中，则找s[i]字符出现的最近的不重复的最大位置m，则L[i+1] = s[m...i+1]
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mapIndex(256,-1);
        int m = 0,longest = 0 ;
        for(int i=0;i<s.length();i++)
        {
            m = max(mapIndex[s[i]]+1,m);
            mapIndex[s[i]] = i;
            longest = max(longest,i-m+1);
        }
        return longest;
    }
};
