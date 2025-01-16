class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

       int m = nums1.size(), n = nums2.size();

       int result = 0;

       if(m%2 != 0){  // nums1 is odd
        for(int i = 0; i < n; i++) // nums2 ke saare elements ka XOR
        result = result^nums2[i];  
       }

        if(n%2 != 0){  // nums2 is odd
        for(int i = 0; i < m; i++) // nums1 ke saare elements ka XOR
        result = result^nums1[i];
       }
     return result;

    }
    
};