class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long start = 1;
        long count = 9;
        while (n > count) {
            n -= count;
            digit += 1;
            start *= 10;
            count = 9 * start * digit;
        }

        int num = start + (n - 1) / digit;
        return static_cast<int>(to_string(num)[(n-1) % digit] - '0');
    }
};