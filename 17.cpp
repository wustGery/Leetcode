class Solution {
public:
    void backTrace(string digits,vector<string>dict,string& curres,vector<string> &res)
    {
        int pos = curres.length();
        if(pos==digits.length())
        {
            res.push_back(curres);
            return;
        }
        int num = digits[pos]-'0';
        int cnt = dict[num].length();
        for(int i=0;i<cnt;i++)
        {
            curres += dict[num][i];
            backTrace(digits,dict,curres,res);
            curres.pop_back();
        }
    }

    vector<string>letterCombinations(string digits)
    {
        initializer_list<string> lst = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxzy"};
        vector<string>dict(lst);
        vector<string>res;
        if(digits.length()==0)  return res;
        string curres = "";
        backTrace(digits,dict,curres,res);
        return res;
    }
};
