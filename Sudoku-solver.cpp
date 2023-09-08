// 8 september 2023
// Sudoku solver
// LC 37

/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/


class Solution {
public:

    bool issafe(int value, vector<vector<char>>& board, int row, int col){
        int n=board.size();
        for(int i=0;i<n;i++){
            // row
            if(board[row][i]==value){
                return false;
            }
            // coll
            if(board[i][col]==value){
                return false;
            }
            //3x3
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==value){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char value='1';value<='9';value++){
                        if(issafe(value,board,i,j)){
                            board[i][j]=value;
                            bool aagekasol=solve(board);
                            if(aagekasol==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
