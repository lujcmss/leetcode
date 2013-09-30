#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    vector<vector<char> > ma;
    vector<string> re;
    string tmp;
    
    void dfs(string &digits, int deep) {
        if (deep == digits.length()) {
            re.push_back(tmp);
            return;
        }
        for (int i = 0; i < ma[digits[deep]-'0'].size(); i++) {
            tmp += ma[digits[deep]-'0'][i];
            dfs(digits, deep+1);
            tmp = tmp.erase(tmp.length()-1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ma.clear();
        vector<char> alp;
        alp.clear();
        ma.push_back(alp); ma.push_back(alp);
        
        for (int i = 2; i < 7; i++) {
            for (int j = (i-2)*3; j < (i-1)*3; j++)
                alp.push_back(j+'a');
            
            ma.push_back(alp);
            alp.clear();
        }
        for (char k = 'p'; k <= 's'; k++)
            alp.push_back(k);
        ma.push_back(alp);
        alp.clear();
        
        for (char k = 't'; k <= 'v'; k++)
            alp.push_back(k);
        ma.push_back(alp);
        alp.clear();
        
        for (char k = 'w'; k <= 'z'; k++)
            alp.push_back(k);
        ma.push_back(alp);
        alp.clear();
        
        re.clear();
        dfs(digits, 0);
        
        return re;
    }
};

int main() {
    string digits = "2";
    
    Solution so;
    vector<string> ans = so.letterCombinations(digits);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}