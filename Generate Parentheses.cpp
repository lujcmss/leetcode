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
    vector<string> re;
    string tmp;
    
    void dfs(int deep, int left, int &goal) {
        if (deep == 0 && left == goal) {
            re.push_back(tmp);
            return;
        }
        
        if (left < goal) {
            tmp += '(';
            dfs(deep + 1, left + 1, goal);
            tmp = tmp.erase(tmp.length() - 1);
        }
        if (deep > 0) {
            tmp += ')';
            dfs(deep - 1, left, goal);
            tmp = tmp.erase(tmp.length() - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        tmp.clear();
        
        dfs(0, 0, n);
        
        return re;
    }
};

int main() {
    
    Solution so;
    vector<string> ans = so.generateParenthesis(0);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}