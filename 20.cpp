class Solution 
{
public:
    bool isMatch(char a,char b)
    {
        if((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}')) return true;
        return false;
    }
    bool isValid(string s) 
    {
        if(s.length()==0) return true;
        if(s.length()%2) return false;
        stack<char>st;
        int s_len = s.length();
        st.push(s[0]);
        for(int i=1;i<s_len;i++)
        {
            if(!st.empty()&&isMatch(st.top(),s[i])) st.pop();
            else st.push(s[i]);
        }
        return st.empty()?true:false;
    }
};
