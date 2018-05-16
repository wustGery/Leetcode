class Solution {
public:
    string convert(string s, int numRows)
    {
        int len = s.length();
        if(numRows==1)  return s;
        if(len==0)  return "0";
        vector<vector<char> > vec;
        vec.resize(numRows);//r行
        for (int k = 0; k < numRows; ++k) {
            vec[k].resize(len);

        }
        for(int i=0;i<numRows;i++)
            for(int j=0;j<vec[0].size();j++)  vec[i][j] = '#';
        cout<<vec[0].size()<<endl;
        int row=0,col=0,cnt=0;
        while(len)
        {
            if(col%(numRows-1)==0)
            {
                vec[row][col] = s[cnt];
                row++;
            }
            else
            {
                vec[row][col] = s[cnt];
                row--;
                col++;
            }
            if(row==numRows)
            {
                row-=2;
                col++;
            }
            --len;
            ++cnt;
        }
        cout<<col<<endl;
        string ans;
        for(int i=0;i<numRows;i++)
            for(int j=0;j<=col;j++)
            {
                if(vec[i][j]!='#')  ans.push_back(vec[i][j]);
            }
        return ans;
    }
};
