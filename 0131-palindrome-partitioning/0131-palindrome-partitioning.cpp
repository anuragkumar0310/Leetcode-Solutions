class Solution {
public:
    vector<vector<string>> partition(string inputStr) {
        vector<vector<string>> finalResult;
        int strLength = inputStr.length();
        unordered_map<int, vector<vector<string>>> memo;

        function<vector<vector<string>>(int)> findPartitions = [&](int startIdx) {
            if (memo.find(startIdx) != memo.end())
                return memo[startIdx];

            if (startIdx >= strLength) {
                return memo[startIdx] = {{}}; 
            }

            vector<vector<string>> tempResult;

            for (int endIdx = startIdx; endIdx < strLength; ++endIdx) {
                string segment = inputStr.substr(startIdx, endIdx - startIdx + 1);
                if (checkPalindrome(segment)) {
                    auto subPartitions = findPartitions(endIdx + 1);
                    for (auto& sub : subPartitions) {
                        vector<string> combined = {segment};
                        combined.insert(combined.end(), sub.begin(), sub.end());
                        tempResult.push_back(combined);
                    }
                }
            }

            return memo[startIdx] = tempResult;
        };

        finalResult = findPartitions(0);
        return finalResult;
    }
    bool checkPalindrome(const string& segment) {
        int leftPtr = 0, rightPtr = segment.length() - 1;
        while (leftPtr < rightPtr) {
            if (segment[leftPtr] != segment[rightPtr])
                return 0;
            ++leftPtr;
            --rightPtr;
        }
        return 1;
    }
};
