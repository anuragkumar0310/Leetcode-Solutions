class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        
        if (n == 1) {
            return derived[0] == 0;  
        }
        
        
        for (int start : {0, 1}) {
            bool valid = true;
            int curr = start;
            
           
            for (int i = 0; i < n - 1; i++) {
                
                int next = curr ^ derived[i];
                curr = next;
            }
            
       
            if ((curr ^ start) == derived[n-1]) {
                return true;
            }
        }
        
        return false;
    }
};