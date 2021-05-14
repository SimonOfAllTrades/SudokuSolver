#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Sudoku {

public:
    vector<vector<int>> board;
    vector<vector<set<int>>> partialBoard;
    int n;

    Sudoku(vector<vector<int>> board, int n): board(board), n(n) {
        
    }

    set<int> fullSet() {
        set<int> ret;
        for (int i = 1; i <= n; ++i) {
            ret.insert(i);
        }
        return ret;
    }

    set<int> getValidNumbers(int row, int col) {
        set<int> ret;
        if (board[row][col] != 0) {
            ret.insert(board[row][col]);
            return ret;
        }

        ret = fullSet();
        // Check the row
        for (int i = 0; i < n; ++i) {
            if (board[row][i] != 0) {
                ret.erase(board[row][i]);
            }
        }

        // Check the column
        for (int i = 0; i < n; ++i) {
            if (board[i][col] != 0) {
                ret.erase(board[i][col]);
            }
        }

        // Check the 3x3
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[3 * (row / 3) + i][3 * (col / 3) + j] != 0) {
                    ret.erase(board[3 * (row / 3) + i][3 * (col / 3) + j]);
                }
            }
        }

        return ret;
    }

    int countRowOccurance(int row, int num) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (partialBoard[row][i].find(num)) {
                ++count;
            }
        }

        return count;
    }

    int countColumnOccurance(int col, int num) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (partialBoard[i][col].find(num)) {
                ++count;
            }
        }

        return count;
    }
    
    // Solving Methods

    void fullHouse() {
        
    }

    void solveSingles() {
        fullHouse();
    }

    Sudoku solve() {
        for (int i = 0; i < n; ++i) {
            vector<set<int>> row;
            for (int j = 0; j < n; ++j) {
                row.push_back(getValidNumbers(i, j));
            }
            partialBoard.push_back(row);
        }
        

    }

    void prettyPrint() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

Sudoku emptySudoku(int n) {
    vector<vector<int>> board = {};
    for (int i = 0; i < n; ++i) {
        vector<int> row = {};
        for (int j = 0; j < n; ++j) {
            row.push_back(0);
        }
        board.push_back(row);
    }
    return Sudoku(board, n);
}

int main() {
    Sudoku mySudoku = emptySudoku(9);
    mySudoku.board[0][0] = 1;
    mySudoku.board[0][1] = 2;
    mySudoku.board[0][2] = 3;
    mySudoku.board[0][3] = 4;
    mySudoku.board[1][1] = 5;
    mySudoku.board[3][0] = 6;

    mySudoku.prettyPrint();

    mySudoku.solve();

    return 0;
}