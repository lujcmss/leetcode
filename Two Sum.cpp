#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> re(2);
        for (int i = 0; i < numbers.size(); i++)
            for (int j = i+1; j < numbers.size(); j++)
                if (numbers[i] + numbers[j] == target) {
                    re[0] = i+1; re[1] = j+1;
                }
        
        return re;
    }
};

int main() {
    vector <int> num(10);
    
    for (int i = 0; i < 10; i++) num[i] = i;
    
    Solution so;
    vector<int> ans = so.twoSum(num, 17);
    cout << ans[0] << endl;
}
