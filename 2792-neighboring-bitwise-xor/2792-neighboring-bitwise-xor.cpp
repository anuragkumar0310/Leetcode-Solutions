class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        if (n == 1) {
            return derived[0] == 0;
        }
        
        int xorSum = 0;
        for (int &nums : derived) {
            xorSum ^= nums;
        }
        
        return xorSum == 0;
    }
};
