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
        for (int i = now; i < candidates.size(); i++) {
            if (i != 0 && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] <= target) {
                tmp.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        re.clear();
        tmp.clear();
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        
        return re;
    }
};

int main() {
    vector<int> a;
    //a.push_back(1);
    //a.push_back(2);
    //a.push_back(3);
    //a.push_back(3);
    //a.push_back(7);
    
    Solution so;
    vector<vector<int> > ans = so.combinationSum(a, 7);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
    
    return 0;
}