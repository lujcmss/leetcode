#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        s.erase(s.begin(), s.begin()+i);

        for (int i = 0; i < s.length() / 2; i++) {
            char tmp = s[i];
            s[i] = s[s.length() - i - 1];
            s[s.length() - i - 1] = tmp;
        }
        
        i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        s.erase(s.begin(), s.begin()+i);
        
        string re = "";
        i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s[j] != ' ') j++;
            for (int k = j-1; k >= i; k--) {
                re += s[k];
            }
            while (j < s.length() && s[j] == ' ') j++;
            
            if (j < s.length()) {
                re += ' ';
                i = j;
            } else {
                break;
            }
        }
        
        s = re;
    }
};

int main() {
    Solution solution;
    
    string s = "   ";
    solution.reverseWords(s);
    
    cout << s << endl;
    return 0;
}
