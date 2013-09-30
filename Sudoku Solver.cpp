#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool flag;
    bool check(vector<vector<char> > &board, int x, int y, int t) {
        for (int i = 0; i < 9; i++)
            if (i != x && board[i][y] == t) return false;
        for (int j = 0; j < 9; j++)
            if (j != y && board[x][j] == t) return false;
        
        for (int i = x/3*3; i < x/3*3+3; i++)
            for (int j = y/3*3; j < y/3*3+3; j++)
                if ((i != x || j != y) && board[i][j] == t) return false;
        
        return true;
    }
    
    void dfs(vector<vector<char> > &board, int deep) {
        if (deep == 81) {
            flag = true;
            return;
        }
        
        if (board[deep/9][deep%9] == '.') {
            for (int k = 1; k < 10; k++) {
                if (!check(board, deep/9, deep%9, k + '0')) continue;
                board[deep/9][deep%9] = k + '0';
                dfs(board, deep+1);
                if (flag) break;
                board[deep/9][deep%9] = '.';
            }
        } else dfs(board, deep+1);
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        flag = false;
        dfs(board, 0);
    }
};

int main() {
    vector<vector<char> > borad(9);
    string s;
    s = "53..7....";
    for (int i = 0; i < 9; i++) borad[0].push_back(s[i]);
    s = "6..195...";
    for (int i = 0; i < 9; i++) borad[1].push_back(s[i]);
    s = ".98....6.";
    for (int i = 0; i < 9; i++) borad[2].push_back(s[i]);
    s = "8...8...3";
    for (int i = 0; i < 9; i++) borad[3].push_back(s[i]);
    s = "4..8.3..1";
    for (int i = 0; i < 9; i++) borad[4].push_back(s[i]);
    s = "7...2...6";
    for (int i = 0; i < 9; i++) borad[5].push_back(s[i]);
    s = ".6....28.";
    for (int i = 0; i < 9; i++) borad[6].push_back(s[i]);
    s = "...419..5";
    for (int i = 0; i < 9; i++) borad[7].push_back(s[i]);
    s = "....8..79";
    for (int i = 0; i < 9; i++) borad[8].push_back(s[i]);
    
    Solution so;
    so.solveSudoku(borad);
    
    for (int i = 0; i < borad.size(); i++, cout << endl)
        for (int j = 0; j < borad[i].size(); j++)
            cout << borad[i][j] << " ";
    
    return 0;
}