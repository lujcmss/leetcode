#include <stdio.h>
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
    void swap(int A[], int x, int y) {
        int tmp = A[x];
        A[x] = A[y];
        A[y] = tmp;
    }
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n-1;
        
        for (int i = 0; i <= r; i++) {
            if (A[i] == 2) {
                while (A[i] == 2 && i <= r) {
                    swap(A, i, r);
                    r--;
                }
            }
            if (A[i] == 0) {
                swap(A, i, l);
                l++;
            }
        }
    }
};

int main() {
    int a[7] = {1, 2, 0, 2, 0, 1, 1};
    
    Solution so;
    so.sortColors(a, 3);
    
    for (int i = 0; i < 7; i++)
        cout << a[i] << " ";
    
    cout << endl;
    
    return 0;
}