class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
    
        unordered_set<int> excludedNumbers(banned.begin(), banned.end());
        
        long long totalSum = 0; 
        int validCount = 0;     

        
        for (int num = 1; num <= n; num++) {
            if (excludedNumbers.find(num) != excludedNumbers.end()) continue; 
            if (totalSum + num > maxSum) break; 
            totalSum += num; 
            validCount++;    
        }

        return validCount; 
    }
};
