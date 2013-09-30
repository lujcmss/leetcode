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
    bool check(vector<vector<char> > &board, int x, int y) {
        for (int i = 0; i < 9; i++)
            if (i != x && board[i][y] == board[x][y]) return false;
        for (int j = 0; j < 9; j++)
            if (j != y && board[x][j] == board[x][y]) return false;
        
        for (int i = x/3*3; i < x/3*3+3; i++)
            for (int j = y/3*3; j < y/3*3+3; j++)
                if ((i != x || j != y) && board[i][j] == board[x][y]) return false;
        
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] != '.') {
                    if (!check(board, i, j)) return false;
                }
        
        return true;
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
    s = "8...6...3";
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
    int ans = so.isValidSudoku(borad);
    
    cout << ans << endl;
    
    return 0;
}