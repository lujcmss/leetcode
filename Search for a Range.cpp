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
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (A[mid] < target) l = mid+1;
            else r = mid;
        }
        int lb = l;
        
        l = 0, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (A[mid] <= target) l = mid+1;
            else r = mid;
        }
        int ub = l - 1;
        
        vector<int> re;
        re.clear();
        
        if (A[lb] == target) {
            re.push_back(lb);
            re.push_back(ub);
        } else {
            re.push_back(-1);
            re.push_back(-1);
        }
        
        return re;
    }
};

int main() {
    int a[20] = {1,3,5,6,6,6,7,7,7,8,8,9};
    
    Solution so;
    vector<int> ans = so.searchRange(a, 12, 4);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}