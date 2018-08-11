class Solution
{
public:
  bool Sudoku_isvalid(int row,int col,vector<vector<char> >& board)
{
    map<char,bool>mp;
    map<char,bool>mp1;
    //mp1.clear();
    for(int i=row;i<row+9;i++)
    {
        mp.clear();
        for(int j=col;j<col+9;j++)
        {
            if(board[i][j]=='.')  continue;
            char ch = board[i][j];
            if(mp[ch])
            {
                cout<<i<<' '<<j<<endl;
                return false;
            }
            else
            {
                mp[ch] = true;
                //mp1[ch] = true;
            }
        }
    }


    for(int j=col;j<col+9;j++)
    {
        mp.clear();
        for(int i=row;i<row+9;i++)
        {
            if(board[i][j]=='.')  continue;
            char ch = board[i][j];
            if(mp[ch])
            {
              //  cout<<i<<' '<<j<<endl;
                return false;
            }
            else  mp[ch] = true;
        }
    }
    return true;
}


bool Sudoku_isvalid1(int row,int col,vector<vector<char> >& board)
{
    map<char,bool>mp;
    mp.clear();
    for(int i=row;i<row+3;i++)
        for(int j=col;j<col+3;j++)
        {
            char ch = board[i][j];
            if(ch=='.') continue;
            if(mp[ch])  return false;
            mp[ch] = true;
        }
    return true;
}


bool isValidSudoku(vector<vector<char>>& board)
{
    if(Sudoku_isvalid(0,0,board)&&Sudoku_isvalid1(0,0,board)&&Sudoku_isvalid1(0,3,board)&&
       Sudoku_isvalid1(0,6,board)&&Sudoku_isvalid1(3,0,board)&&Sudoku_isvalid1(3,3,board)&&
       Sudoku_isvalid1(3,6,board)&&Sudoku_isvalid1(6,0,board)&&Sudoku_isvalid1(6,3,board)&&
       Sudoku_isvalid1(6,6,board))  return true;
    return false;
}
};
