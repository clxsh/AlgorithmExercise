class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;

        int divisor = 1000000007;
        int64_t x = 3;
        int64_t res = 1;
        int remainder = n % 3;
        
        for (int a = n / 3 - 1; a > 0; a /= 2) {
            if (a & 1)
                res = (res * x) % divisor;
            
            x = (x * x) % divisor;
        }

        if (remainder == 0)
            return res * 3 % divisor;
        else if (remainder == 1)
            return res * 4 % divisor;
        else
            return res * 6 % divisor;
    }
};