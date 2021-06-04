class Solution {
public:
    double myPow(double x, int n) {
        bool neg = n < 0 ? true : false;
        double res = 1;

        while (n) {
            if (n & 1) res = res * x;
            x = x * x;
            n = n / 2;
        }

        return neg? 1 / res : res;
    }
};