class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>rows(9);
        vector<set<char>>cols(9);
        vector<set<char>>boxes(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               if(board[i][j]=='.')continue;
               int boxId = ((i/3)*3+j/3);
               auto it1 = rows[i].find(board[i][j]);
               auto it2 = cols[j].find(board[i][j]);
               auto it3 = boxes[boxId].find(board[i][j]);
               if(it1!=rows[i].end()||it2!=cols[j].end()||it3!=boxes[boxId].end())
               {
                   return false;
               }
               rows[i].insert(board[i][j]);
               cols[j].insert(board[i][j]);
               boxes[boxId].insert(board[i][j]);
            }
        }
        return true;
    }
};
