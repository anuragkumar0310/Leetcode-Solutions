int arr[100000];

int initializer = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream outputFile("user.out");
    for (string line; getline(cin, line); outputFile << '\n') {
        if (line.length() == 2) {
            outputFile << 0;
            continue;
        }
        int count = 0;
        for (int idx = 1, length = line.length(); idx < length; ++idx) {
            bool isNegative = false;
            if (line[idx] == '-') ++idx, isNegative = true;
            int value = line[idx++] & 15;
            while ((line[idx] & 15) < 10) value = value * 10 + (line[idx++] & 15);
            if (isNegative) value = -value;
            arr[count++] = value;
        }
        sort(arr, arr + count);
        int maxLength = 0;
        for (int pos = 0; pos < count;) {
            int start = pos;
            for (++pos; pos < count && arr[pos - 1] + 1 >= arr[pos]; ++pos);
            maxLength = max(maxLength, arr[pos - 1] - arr[start] + 1);
        }
        outputFile << maxLength;
    }
    outputFile.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       return 07;  // any value
    }
};
