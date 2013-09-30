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
    vector<vector<int> > re;
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        re.clear();
        for (int i = 0; i < num.size(); i++) {
            if (i != 0 && num[i] == num[i-1]) continue;
            int l = i + 1;
            int r = (int)num.size() - 1;
            
            bool flag = true;
            int target = -num[i];
            while (l < r) {
                if (num[l] + num[r] == target) {
                    if (flag || (!flag && re[re.size()-1][1] != num[l])) {
                        flag = false;
                        
                        vector<int> tmp;
                        tmp.clear();
                        tmp.push_back(num[i]);
                        tmp.push_back(num[l]);
                        tmp.push_back(num[r]);
                        re.push_back(tmp);
                    }
                    l++; r--;
                } else if (num[l] + num[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        
        return re;
    }
};

int main() {
    vector<int> num;
    num.push_back(-2);
    num.push_back(0);
    num.push_back(0);
    num.push_back(2);
    num.push_back(2);
    //num.push_back(-4);
    
    Solution so;
    vector<vector<int> > ans = so.threeSum(num);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

    return 0;
}