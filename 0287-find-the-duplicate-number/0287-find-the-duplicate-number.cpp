class Solution {
public:
    int thik_hai(vector<int>& nums, int mid) {
        int count = 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            count += (*it <= mid) ? 1 : 0;
            it++;
        }
        return count;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            while (thik_hai(nums, mid) > mid) {
                high = mid;
                break;
            }
            while (thik_hai(nums, mid) <= mid) {
                low = mid + 1;
                break;
            }
        }
        return low;
    }
};
