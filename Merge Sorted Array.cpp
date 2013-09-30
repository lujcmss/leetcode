#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> tmp;
        tmp.clear();
        
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (j == n || (i < m && A[i] < B[j])) {
                tmp.push_back(A[i++]);
            }
            else tmp.push_back(B[j++]);
        }
        
        for (int i = 0; i < tmp.size(); i++)
            A[i] = tmp[i];
    }
};

int main() {
    int a[10] = {1, 2, 3};
    int b[4] = {3, 4, 5, 6};
    
    Solution so;
    so.merge(a, 3, b, 4);
    
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    
    return 0;
}