class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = static_cast<unsigned>(a & b) << 1;   // 进位
            a ^= b;                 // 非进位
            b = c;
        }

        return a;
    }
};