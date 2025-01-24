class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMaxProductSubarr = nums[0];
        int currMinProductSubarr = nums[0];
        int maxProductAns = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = currMaxProductSubarr;
            currMaxProductSubarr = max({nums[i], currMaxProductSubarr * nums[i], currMinProductSubarr * nums[i]});
            currMinProductSubarr = min({nums[i], temp * nums[i], currMinProductSubarr * nums[i]});
            maxProductAns = max(maxProductAns, currMaxProductSubarr);
        }
        return maxProductAns;
    }
};