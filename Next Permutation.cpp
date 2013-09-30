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
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 2) return;
        
        int x = (int)num.size()-2;
        while (x >= 0) {
            if (num[x] >= num[x+1]) x--;
            else break;
        }
        if (x == -1) {
            sort(num.begin(), num.end());
        } else {
            int y = x + 1;
            for (int i = x + 1; i < num.size(); i++)
                if (num[i] > num[x]) y = i;
            
            int tmp = num[x];
            num[x] = num[y];
            num[y] = tmp;
            
            for (int i = x + 1; i < num.size(); i++) {
                int j = (int)num.size() - i + x;
                
                if (i >= j) break;
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
};

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    //num.push_back(2);
    
    Solution so;
    so.nextPermutation(num);
    
    for (int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    
    return 0;
}