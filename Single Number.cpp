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
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int re = 0;
        for (int i = 0; i < n; i++) re ^= A[i];
        return re;
    }
};

int main() {
    int a[10] = {1,2,2,3,3,4,4};
    
    Solution so;
    int ans = so.singleNumber(a, 9);
    
    cout << ans;
    
    return 0;
}