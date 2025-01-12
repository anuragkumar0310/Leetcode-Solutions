#include <bits/stdc++.h>
using namespace std;

class Nexify07 {
public:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

private:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            arr[k++] = (leftArr[i] <= rightArr[j]) ? leftArr[i++] : rightArr[j++];
        }
        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];
    }
};

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> nextGreaterIdx(sz, -1);
        vector<int> stack;
        int i = 0;
        while (i < sz) {
            while (!stack.empty() && nums[i] > nums[stack.back()]) {
                nextGreaterIdx[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
            i++;
        }

        vector<long long> prefixSum(sz, 0);
        prefixSum[0] = nums[0];
        i = 1;
        while (i < sz) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
            i++;
        }

        auto calculateOps = [&](int target, int left, int right) -> long long {
            if (!(0 <= left && left < sz && 0 <= right && right < sz)) return 0LL;
            if (right < left) return 0LL;
            long long sum = prefixSum[right] - (left ? prefixSum[left - 1] : 0);
            int len = right - left + 1;
            return 1LL * target * len - sum;
        };

        long long result = 0, operations = 0;
        int left = 0, right = 0;
        set<int> fixedPoints{0};
        while (right < sz) {
            if (right < (sz - 1)) {
                int back = nums[*fixedPoints.rbegin()];
                long long expandOps = (nums[right + 1] >= back) ? 0 : back - nums[right + 1];
                if (operations + expandOps <= k) {
                    if (nums[right + 1] > back) fixedPoints.insert(right + 1);
                    operations += expandOps;
                    right++;
                    continue;
                }
            }
            result += right - left + 1;

            if (left == right) {
                left++, right++;
                operations = 0;
                fixedPoints = {left};
                continue;
            }

            fixedPoints.erase(left);
            int second = fixedPoints.empty() ? (right + 1) : *fixedPoints.begin();
            operations -= calculateOps(nums[left], left + 1, second - 1);

            int currFixedPoint = left + 1;
            while (0 <= currFixedPoint && currFixedPoint < second) {
                int nextIdx = nextGreaterIdx[currFixedPoint];
                if (0 <= nextIdx && nextIdx < second) {
                    operations += calculateOps(nums[currFixedPoint], currFixedPoint + 1, nextIdx - 1);
                } else {
                    operations += calculateOps(nums[currFixedPoint], currFixedPoint + 1, second - 1);
                }
                fixedPoints.insert(currFixedPoint);
                currFixedPoint = nextIdx;
            }

            left++;
        }
        return result;
    }
};
