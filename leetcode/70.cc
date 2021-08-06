class Solution {
public:
    int climbStairs(int n) {
        int64_t a = 1;
        int64_t b = 2;
        int64_t c;

        for (int i = 1; i < n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }

        return a;
    }
};