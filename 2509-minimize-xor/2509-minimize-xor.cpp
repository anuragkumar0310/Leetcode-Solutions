class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int countBits = countOnes(num1);
        int targetBits = countOnes(num2);
        if (countBits == targetBits) {
            return num1;
        }
        int result = num1;
        if (countBits < targetBits) {
            int bitsToAdd = targetBits - countBits;
            int index = 0;
            while (bitsToAdd) {
                if (!(result & (1 << index))) {
                    result = result | (1 << index);
                    bitsToAdd--;
                }
                index++;
            }
            return result;
        } else {
            int bitsToRemove = countBits - targetBits;
            int index = 0;
            while (bitsToRemove) {
                if (result & (1 << index)) {
                    result = result ^ (1 << index);
                    bitsToRemove--;
                }
                index++;
            }
        }
        return result;
    }
    int countOnes(int value) {
        int bitCount = 0;
        while (value) {
            bitCount += value & 1;
            value = value >> 1;
        }
        return bitCount;
    }
};
