class Solution {
public:
    string reverseWords(string input) {
        reverse(input.begin(), input.end());
        int size = input.size();
        int start = 0;
        int end = 0;
        int index = 0;

        while (index < size) {
            while (index < size && input[index] == ' ') index++;
            if (index == size) break; 
            while (index < size && input[index] != ' ') {
                input[end++] = input[index++];
            }
            reverse(input.begin() + start, input.begin() + end);
            input[end++] = ' ';
            start = end;
            index++;
        }
        input.resize(end - 1);
        return input;
    }
};
