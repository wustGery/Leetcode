#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;



vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int>ans;
    if(s.length()==0||words.size()==0)  return ans;
    int i,j;
    int s_len = s.length();
    int l_size = words.size();
    map<string,int>word_count;  //记录每一个串在words中出现的次数
    for(i=0;i<l_size;i++)
       ++word_count[words[i]];
    int word_size = words[0].length();
    map<string,int>counting; //记录在查找过程中的次数
    for(i=0;i<=s_len-l_size*word_size;i++)
    {
        counting.clear();
        for(j=0;j<l_size;j++)
        {
            string ss = s.substr(i+j*word_size,word_size); //对每个子串进行遍历
            if(word_count.find(ss)!=word_count.end())
            {
                ++counting[ss];
                if(counting[ss]>word_count[ss]) break;
            }
            else break;
        }
        if(j==l_size)  ans.push_back(i);
    }
    return ans;
}



int main()
{
    string s = "wordgoodstudentgoodword";
    initializer_list<string> lst = {"word","student"};
    vector<string>words(lst);
    vector<int>ans = findSubstring(s,words);
    vector<int>::iterator iter = ans.begin();
    for(;iter!=ans.end();iter++) cout<<*iter;
    return 0;
}

