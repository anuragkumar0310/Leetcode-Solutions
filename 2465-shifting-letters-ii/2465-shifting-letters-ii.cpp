class nexify07 {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
        vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);
        int i = 0, j = 0, k = low;

        while (i < left.size() && j < right.size()) {
            arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        }

        while (i < left.size()) {
            arr[k++] = left[i++];
        }

        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
};

class Solution {
public:
    string shiftingLetters(string str, vector<vector<int>>& shifts) {
        int len = str.size();
        vector<int> shiftArr(len + 1, 0);

        int i = 0;
        while (i < shifts.size()) {
            int startIdx = shifts[i][0], endIdx = shifts[i][1], dir = shifts[i][2];
            shiftArr[startIdx] += (dir == 1 ? 1 : -1);
            shiftArr[endIdx + 1] -= (dir == 1 ? 1 : -1);
            i++;
        }

        int accumulatedShift = 0;
        int j = 0;
        while (j < len) {
            accumulatedShift += shiftArr[j];
            shiftArr[j] = accumulatedShift;
            j++;
        }

        int k = 0;
        while (k < len) {
            int totalShift = (shiftArr[k] % 26 + 26) % 26;
            str[k] = 'a' + (str[k] - 'a' + totalShift) % 26;
            k++;
        }

        return str;
    }
};
