class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) 
              return mid;

            nums[low] <= nums[mid]
                ? (nums[low] <= target && target < nums[mid] ? high = mid - 1 : low = mid + 1)
                : (nums[mid] < target && target <= nums[high] ? low = mid + 1 : high = mid - 1);
        }
        return -1;
    }
};
