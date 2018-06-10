class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==0)  return "";
        int ans;
        string commonPrefix = "";
        bool ok = true;
        int size = strs.size();
        string pre = "";
        pre+=strs[0][0];
        vector<string>prefix;
        prefix.push_back(pre);
        for(int i=1;i<strs[0].size();i++) 
        {
            pre += strs[0][i];
            prefix.push_back(pre);
        }
        int prefix_cnt = 0;
        int prefix_size= prefix.size();
        for(int i=0;i<prefix_size;i++)
        {
            ans = i;
            string temp = prefix[i];
            for(int j = 1;j< size;j++)
            {
                string s = "";
                for(int k=0;k<i+1;k++)  s+=strs[j][k];
                if(temp!=s)  
                {
                    ok = false;
                    break;
                }
            }
            if(!ok)
            {
                ans -=1 ;
                break;
            }
        }
        if(ans==-1) return commonPrefix;
        for(int i=0;i<=ans;i++) commonPrefix.push_back(strs[0][i]);
        return commonPrefix;
    }
};
