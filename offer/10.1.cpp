class Solution {
public:
/*
int fib(int n)
    {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }

        return fib(n-2) + fib(n-1);
    }
*/
    int fib(int n) {
        int a = 0, b = 1, sum = 0;

        for (int i = 0; i < n; ++i) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }

        return a;
    }
};