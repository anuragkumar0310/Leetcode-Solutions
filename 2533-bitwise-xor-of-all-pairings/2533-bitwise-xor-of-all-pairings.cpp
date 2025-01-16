class Solution {
public:
    int xorAllNums(vector<int>& array1, vector<int>& array2) {
        int len1 = array1.size(), len2 = array2.size();
        int result = 0;
        if(len2 % 2){
            for(auto value: array1)
                result ^= value;
        }
        if(len1 % 2){
            for(auto value: array2)
                result ^= value;
        }
        return result;
    }
};
