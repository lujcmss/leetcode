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
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word1.length() * word2.length() == 0) return (int)(word1.length()+word2.length());
        
        vector<vector<int> > f(word1.length()+1, vector<int>(word2.length()+1));
        
        for (int i = 0; i <= word1.length(); i++) f[i][0] = i;
        for (int j = 0; j <= word2.length(); j++) f[0][j] = j;
        
        for (int i = 1; i <= word1.length(); i++)
            for (int j = 1; j <= word2.length(); j++)
                if (word1[i-1] == word2[j-1]) f[i][j] = f[i-1][j-1];
                else f[i][j] = min(f[i-1][j], min(f[i][j-1], f[i-1][j-1]))+1;
        
        return f[word1.length()][word2.length()];
    }
};

int main() {
    string w1 = "asdfasdf";
    string w2 = "adsfasd";
    
    Solution so;
    int ans = so.minDistance(w1, w2);
    
    cout << ans << endl;
    
    return 0;
}