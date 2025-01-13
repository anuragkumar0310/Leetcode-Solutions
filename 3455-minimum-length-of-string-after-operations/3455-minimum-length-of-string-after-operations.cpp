class Solution {
public:
    int minimumLength(string str) {
        vector<int> frequency(26, 0);
        int result = 0;
        
        for (char ch : str) {
            frequency[ch - 'a']++;
        }
        
        for (int count : frequency) {
            if (count == 0) continue;
            result += (count % 2 == 0) ? 2 : 1;
        }        
        return result;
    }
};
