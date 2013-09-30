#include <stdio.h>
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
    bool dfs(vector<vector<char> > &board, int x, int y, string w) {
        if (w.length() == 0) return true;
        
        char ch = board[x][y];
        board[x][y] = '\0';
        if (x > 0 && board[x-1][y] == w[0]) if (dfs(board, x-1, y, w.substr(1))) return true;
        if (y > 0 && board[x][y-1] == w[0]) if (dfs(board, x, y-1, w.substr(1))) return true;
        if (x < board.size()-1 && board[x+1][y] == w[0]) if (dfs(board, x+1, y, w.substr(1))) return true;
        if (y < board[0].size()-1 && board[x][y+1] == w[0]) if (dfs(board, x, y+1, w.substr(1))) return true;
        
        board[x][y] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0) return true;
        
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0] && dfs(board, i, j, word.substr(1))) return true;
        return false;
    }
};

int main() {
    vector<vector<char> > board(2, vector<char>(2));
    board[0][0] = 'a'; board[0][1] = 'b';
    board[1][0] = 'b'; board[1][1] = 'b';
    
    Solution so;
    bool ans = so.exist(board, "bba");
    
    cout << ans << endl;
    
    return 0;
}