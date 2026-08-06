class Solution {
public:
    bool backtrack(vector<vector<char>>&board,int row,int col,int idx,string word)
    {
        int n=board.size(),m=board[0].size();
        if(idx==word.size())return true;
        if(row>=n||row<0||col>=m||col<0||board[row][col]!=word[idx])return false;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        bool found=false;
        char temp = board[row][col];
        board[row][col]='#';
        for(int i=0;i<4;i++)
        {
            if(backtrack(board,row+dr[i],col+dc[i],idx+1,word))found=true;
        }
        board[row][col]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(backtrack(board,i,j,0,word))return true;
            }
        }
        return false;
    }
};
