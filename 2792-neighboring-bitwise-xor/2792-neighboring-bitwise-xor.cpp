class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        
        for (int first = 0; first <= 1; first++) {
            vector<int> original(n);

            
            original[0] = first;

            
            for (int i = 1; i < n; i++) {
                original[i] = derived[i - 1] ^ original[i - 1];
            }

            
            if ((original[n - 1] ^ original[0]) == derived[n - 1]) {
                return true; 
            }
        }

        
        return false;
    }
};
