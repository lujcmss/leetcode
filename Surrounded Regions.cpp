#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void ffill(vector<vector<char> > &board, int x, int y) {
        board[x][y] = 'T';
        if (x > 0 && board[x-1][y] == 'O') ffill(board, x-1, y);
        if (y > 0 && board[x][y-1] == 'O') ffill(board, x, y-1);
        if (x < board.size()-1 && board[x+1][y] == 'O') ffill(board, x+1, y);
        if (y < board[x].size()-1 && board[x][y+1] == 'O') ffill(board, x, y+1);
    }
public:
    void solve(vector<vector<char> > &board) {
        if (board.size() == 0) return;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') ffill(board, i, 0);
            if (board[i][board[i].size()-1] == 'O') ffill(board, i, (int)board[i].size()-1);
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[0][j] == 'O') ffill(board, 0, j);
            if (board[board.size()-1][j] == 'O') ffill(board, (int)board.size()-1, j);
        }
        
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == 'T') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
    }
};

int main() {
    vector<vector<char> > ans;
    /*for (int i = 0; i < 4; i++) {
        vector<char> tmp;
        for (int j = 0; j < 4; j++) tmp.push_back('X');
        ans.push_back(tmp);
    }
    ans[0][1] = 'O'; ans[2][2] = 'O';
    */
    Solution so;
    so.solve(ans);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
