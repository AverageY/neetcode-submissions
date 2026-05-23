class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check numbers in a row is unique across all rows
        for(int i = 0; i<9; i++){
            vector<bool> seen(10,false);
            for(char c: board[i]){
            if(c=='.') continue;
            int num = c -'0';
            if(seen[num]==true) return false;
            seen[num]=true;
            }
        }

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
