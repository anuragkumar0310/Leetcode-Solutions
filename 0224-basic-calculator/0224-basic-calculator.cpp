class Solution {
public:
    int calculate(string s) {
        deque<int> dequeResult;
        int number = 0;
        int result = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += number * sign;
                sign = (c == '-') ? -1 : 1;
                number = 0;
            } else if (c == '(') {
                dequeResult.push_back(result);
                dequeResult.push_back(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += number * sign;
                result *= dequeResult.back();
                dequeResult.pop_back();
                result += dequeResult.back();
                dequeResult.pop_back();
                number = 0;
            }
        }

        return result + number * sign;
    }
};
