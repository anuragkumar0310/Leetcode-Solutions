class nexify07 {
public:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1, n2 = right - mid;
        vector<int> L(n1), R(n2);
        int i = 0, j = 0;
        while (i < n1) L[i] = arr[left + i], i++;
        while (j < n2) R[j] = arr[mid + 1 + j], j++;
        int k = left; i = 0; j = 0;
        while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
};

class Solution {
public:
    inline bool compareArrays(array<int, 26>& firstArray, array<int, 26>& secondArray) {
        int idx = 0;
        while (idx < 26) {
            if (firstArray[idx] < secondArray[idx]) return 0;
            idx++;
        }
        return 1;
    }

    vector<string> wordSubsets(vector<string>& primaryWords, vector<string>& secondaryWords) {
        array<int, 26> globalMax = {0};
        auto it = secondaryWords.begin();
        while (it != secondaryWords.end()) {
            array<int, 26> freqArray = {0};
            int charIdx = 0;
            while (charIdx < (*it).size()) freqArray[(*it)[charIdx++] - 'a']++;
            int i = 0;
            while (i < 26) globalMax[i] = (globalMax[i] > freqArray[i]) ? globalMax[i] : freqArray[i], i++;
            ++it;
        }

        vector<string> result;
        result.reserve(primaryWords.size());
        auto wordIt = primaryWords.begin();
        while (wordIt != primaryWords.end()) {
            array<int, 26> freqArray = {0};
            int charIdx = 0;
            while (charIdx < (*wordIt).size()) freqArray[(*wordIt)[charIdx++] - 'a']++;
            compareArrays(freqArray, globalMax) ? result.push_back(*wordIt) : void();
            ++wordIt;
        }
        return result;
    }
};
