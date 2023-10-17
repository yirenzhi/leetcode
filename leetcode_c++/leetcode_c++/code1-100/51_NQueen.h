#pragma once

#include "../base.h"
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

class Solution51 : public Solution
{
private:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backtrack(board,0);

        return res;
    }

    void backtrack(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }

        for (auto col = 0; col < board.size(); col++)
        {
            // if isvalue
            if (!isValue(board, row, col))
            {
                continue;
            }

            board[row][col] = 'Q';

            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }

    bool isValue(vector<string> &board, int row, int col)
    {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (auto i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        // 检查左右上方斜线是否有冲突

        //左上角

        for (auto i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        for (auto i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

public:
    void test()
    {
        auto res = solveNQueens(4);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {

                cout << res[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
