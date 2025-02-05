class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> idx;
        int count = 0;

        for (int i = 0; i < s1.size(); i++) {
            if ((s1[i] ^ s2[i]) != 0) {
                idx.push_back(i);
                count++;
                if (count > 2)
                    return false;
            }
        }

        return count == 0 || (count == 2 && s1[idx[0]] == s2[idx[1]] &&
                              s1[idx[1]] == s2[idx[0]]);
    }
};