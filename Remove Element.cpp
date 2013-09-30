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
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i = 0; i < n; i++)
            if (A[i] == elem) {
                while (i < n && A[i] == elem) {
                    A[i] = A[--n];
                }
            }
        
        return n;
    }
};

int main() {
    int a[20] = {2,2,2,3,4,5,2,2,4};
    
    Solution so;
    int ans = so.removeElement(a, 3, 2);
    
    cout << ans << endl;
    
    return 0;
}