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
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> re;
        re.clear();
        
        int num;
        vector<string> tmp;
        
        tmp.clear(); num = 0;
        for (int i = 0; i < words.size(); i++) {
            if (num + words[i].length() <= L) {
                tmp.push_back(words[i]);
                num += words[i].length() + 1;
            } else {
                int tot = 0;
                for (int i = 0; i < tmp.size(); i++)
                    tot += tmp[i].length();
                
                string s = "";
                for (int i = 0; i < tmp.size(); i++) {
                    s += tmp[i];
                    if (tmp.size() == 1) {
                        for (int j = 0; j < L-tot; j++) s += " ";
                    } else  {
                        if (i != tmp.size()-1)
                            for (int j = 0; j < (L-tot)/(tmp.size()-1); j++) s += " ";
                        if (i < (L-tot)%(tmp.size()-1)) s += " ";
                    }
                }
                
                re.push_back(s);
                tmp.clear();
                
                tmp.push_back(words[i]);
                num = (int)words[i].length()+1;
            }
        }
        
        string s = "";
        for (int i = 0; i < tmp.size(); i++) {
            s += tmp[i];
            if (i != tmp.size()-1) s += " ";
        }
        while (s.length() < L) s += " ";
        re.push_back(s);
        
        return re;
    }
};

int main() {
    vector<string> words;
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("e");
    //words.push_back("text");
    //words.push_back("justification.");
    
    Solution so;
    vector<string> ans = so.fullJustify(words, 3);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}