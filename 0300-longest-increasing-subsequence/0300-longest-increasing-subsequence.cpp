class Solution {
public:

    int findMaxLength(int currentIndex, int previousIndex, vector<int>& sequence, int size, vector<vector<int>>& memo) {
        if(currentIndex == size) return 0;
        if(memo[currentIndex][previousIndex+1] != -1) return memo[currentIndex][previousIndex+1];    
        int maxLength = 0 + findMaxLength(currentIndex+1, previousIndex, sequence, size, memo);

        if(previousIndex == -1 || sequence[currentIndex] > sequence[previousIndex]) {
            maxLength = max(maxLength, 1 + findMaxLength(currentIndex+1, currentIndex, sequence, size, memo));
        }
        return memo[currentIndex][previousIndex+1] = maxLength;
    }

    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> memo(size, vector<int>(size+1, -1));
        return findMaxLength(0, -1, nums, size, memo);
    }
};
