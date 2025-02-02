class Solution {
public:
    bool check(vector<int>& nums) {
        int pk = 0;
        

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pk = i + 1; 
                break;
            }
        }
        
        
        for (int i = pk; i < nums.size() + pk - 1; i++) {
           
            if (nums[i % nums.size()] > nums[(i + 1) % nums.size()]) {
                return 0; 
            }
        }
        
        return 1; 
    }
};