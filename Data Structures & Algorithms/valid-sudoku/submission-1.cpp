#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int boxLoc(int i, int j)
    {
        if (i < 3 && j < 3)
            return 1;
        if (i < 3 && j >= 3 && j < 6)
            return 2;
        if (i < 3 && j >= 6)
            return 3;

        if (i >= 3 && i < 6 && j < 3)
            return 4;
        if (i >= 3 && i < 6 && j >= 3 && j < 6)
            return 5;
        if (i >= 3 && i < 6 && j >= 6)
            return 6;

        if (i >= 6 && j < 3)
            return 7;
        if (i >= 6 && j >= 3 && j < 6)
            return 8;
        if (i >= 6 && j >= 6)
            return 9;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool col[10][10] = {}, box[10][10] = {}, row[10] = {};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int n = board[i][j] - '0';
                    if (col[j][n])
                        return false;
                    if (box[boxLoc(i, j)][n])
                        return false;
                    if (row[n])
                        return false;

                    col[j][n] = true;
                    box[boxLoc(i, j)][n] = true;
                    row[n] = true;
                }
            }
            memset(row, false, sizeof(row));
        }

        return true;
    }
};
