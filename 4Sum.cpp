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
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        re.clear();
        
        for (int i = 0; i < num.size(); i++) {
            if (i && num[i] == num[i-1]) continue;
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j-1]) continue;
                
                int l = j + 1, r = (int)num.size() - 1;
                bool flag = true;
                int ttar = target - num[i] - num[j];
                while (l < r) {
                    if (num[l] + num[r] == ttar) {
                        if (flag || (!flag && re[re.size()-1][2] != num[l])) {
                            flag = false;
                            
                            vector<int> tmp;
                            tmp.clear();
                            tmp.push_back(num[i]);
                            tmp.push_back(num[j]);
                            tmp.push_back(num[l]);
                            tmp.push_back(num[r]);
                            re.push_back(tmp);
                        }
                        l++; r--;
                    } else if (num[l] + num[r] < ttar) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return re;
    }
};

int main() {
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    
    Solution so;
    vector<vector<int> > ans = so.fourSum(num, 4);
    
    for (int i = 0; i < ans.size(); i++, cout << endl)
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

    return 0;
}