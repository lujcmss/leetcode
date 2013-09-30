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
    
    void dfs(vector<int> & candidates, int target, int now) {
        if (target == 0) {
            re.push_back(tmp);
            return;
        }
        if (now == candidates.size()) return;
        
        int end = now+1;
        while (end < candidates.size() && candidates[end] == candidates[now]) end++;
        
        for (int i = now; i <= end; i++) {
            if (candidates[now] * (i - now) <= target) {
                for (int j = now; j < i; j++) tmp.push_back(candidates[now]);
                dfs(candidates, target - candidates[now] * (i - now), end);
                for (int j = now; j < i; j++) tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        tmp.clear();
        
        sort(num.begin(), num.end());
        dfs(num, target, 0);
        
        return re;
    }
};

int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);
    
    Solution so;
    vector<vector<int> > ans = so.combinationSum2(a, 3);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
    return 0;
}