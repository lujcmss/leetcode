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
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i = 0; i < n; i++) {
            if (A[i] == i+1) continue;
            while (A[i] != i+1 && A[i] > 0 && A[i] <= n) {
                int index = A[i]-1;
                if (A[index] == index + 1) break;
                
                int tmp = A[i];
                A[i] = A[index];
                A[index] = tmp;
            }
        }
        
        for (int i = 0; i < n; i++)
            if (A[i] != i+1) return i+1;
        
        return n+1;
    }
};

int main() {
    int a[20] = {1,2,3,5,4,0,1,3,2,1,2,1};
    int n = 5;
    
    Solution so;
    int ans = so.firstMissingPositive(a, n);
    
    cout << ans << endl;
    
    return 0;
}