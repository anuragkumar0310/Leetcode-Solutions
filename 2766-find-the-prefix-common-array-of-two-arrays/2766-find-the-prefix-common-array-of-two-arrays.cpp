class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int length = A.size();
        bitset<51> seenInFirst = 0, seenInSecond = 0;
        vector<int> result(length, 0);
        
        for(int index = 0; index < length; index++) {
            int currentFirst = A[index];
            int currentSecond = B[index];
            
            seenInFirst[currentFirst] = 1;
            seenInSecond[currentSecond] = 1;
            result[index] = (seenInFirst & seenInSecond).count();
        }
        
        return result;
    }
};