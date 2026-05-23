#include <iostream>


using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check numbers in a row is unique across all rows
        // make seen of size 10 because c-'0' gives 1 to 9, so we only need to check for 1 to 9 and ignore 0 index, for convenience
        for(int i = 0; i<9; i++){
            vector<bool> seen(10,false);
            for(char c: board[i]){
            if(c=='.') continue;
            int num = c -'0';
            if(seen[num]==true) return false;
            seen[num]=true;
            }
        }

        // check numbers in a column is unique across all columns
        // to do this first flip the row and column index in the nested loop and then do the same check as we did for rows
        for(int col = 0; col < 9; col++) {
            vector<bool> seen(10, false);
            for(int row = 0; row < 9; row++) {
                char c = board[row][col];
                if(c == '.') continue;
                int num = c - '0';
                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        // to check 3x3 boxes
        // outer loop runs (n/3 * n/3 times if sudoku was nxn)
        // inner loop runs 3x3 times
        // so overall this 4 nested loop is o(n^2) only
        for (int i =0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                vector<int> seen(10,false);
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        char c = board[x][y];

                        if (c == '.') continue;

                        int num = c - '0';
                        if (seen[num]) return false;

                        seen[num] = true;
                    }
                }
            }
        }

        return true;
        
    }
};
