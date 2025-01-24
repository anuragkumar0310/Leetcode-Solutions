class Solution {
public:
    bool check(string &a, string &b) {
        int m = a.size();
        int n = b.size();
        int i = 0;
        while (i <= m - n) {
            int j = 0;
            while (j < n) {
                if (a[i + j] != b[j]) break;
                j++;
            }
            if (j == n) return true;
            i++;
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();
        int ans = 1;
        string tmp = a;
        
        while (a.size() < b.size()) {
            a += tmp;
            ans++;
        }
        
        if (check(a, b)) {
            return ans;
        }
        
        a += tmp;
        if (check(a, b)) {
            return ans + 1;
        }
        
        return -1;
    }
};