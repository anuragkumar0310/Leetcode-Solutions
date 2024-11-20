#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int prev1 = 1, prev2 = 1, current = 0, index = 1;

        while (index < n + 1) {
            current = 0;
            current += (s[index - 1] != '0') ? prev1 : 0;
            current += (index > 1 && (s[index - 2] == '1' || (s[index - 2] == '2' && s[index - 1] <= '6'))) ? prev2 : 0;

            prev2 = prev1;
            prev1 = current;
            index++;
        }
        return prev1;
    }
};
