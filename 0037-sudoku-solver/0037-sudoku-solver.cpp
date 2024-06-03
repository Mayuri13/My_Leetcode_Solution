class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char ch){
        for(int i=0; i<9; i++){
            if(board[i][col] == ch) return false;  //Checking horizontally

            if(board[row][i] == ch) return false;   //Checking vertically

            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch) return false;   //Checking in the 3x3 sub-matrices
        }
        return true;
    }

    bool find(vector<vector<char>>& board){
        //Searching for the empty cells
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    
                    //Trying all digits from 0 - 9
                    for(char ch = '1'; ch <= '9'; ch++){

                        if(isSafe(i,j,board,ch)){
                            //If it is safe, then place ch in it
                            board[i][j] = ch;

                            //Making next recursive call after placing ch
                            if(find(board))
                                return true;
                            else{
                                //If after placing ch no valid sudoko found, then make it empty again
                                board[i][j] = '.';
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
        find(board);
    }
};