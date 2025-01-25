class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        
        long long dd = abs((long long)dividend);
        long long dv = abs((long long)divisor);
        
        int res = 0;
        while(dv <= dd) {
            long long sum = dv, count = 1;
            while(sum <= dd - sum) {
                sum += sum;
                count += count;
            }
            res += count;
            dd -= sum;
        }
        
        return (dividend < 0) ^ (divisor < 0) ? -res : res;
    }
};