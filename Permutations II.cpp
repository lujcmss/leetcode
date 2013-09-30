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
    vector<vector<int> > re;
    vector<int> tmp;
    vector<int> choose;
    
    void dfs(vector<int> &num, int deep, const int &goal) {
        if (deep == goal) {
            re.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < goal; i++) {
            if (!choose[i] && (i == 0 || num[i] != num[i-1])) {
                choose[i] = 1;
                tmp.push_back(num[i]);
                num[i]--;
                
                dfs(num, deep+1, goal);
                
                num[i]++;
                tmp.pop_back();
                choose[i] = 0;
            }
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        re.clear();
        tmp.clear();
        choose.clear();
        choose.resize(num.size());
        
        if (num.size() == 0) return re;
        dfs(num, 0, (int)num.size());
        
        return re;
    }
};

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    
    Solution so;
    vector<vector<int> > ans = so.permuteUnique(num);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] <<  " ";
    
    return 0;
}