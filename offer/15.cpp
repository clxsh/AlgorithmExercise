class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (; n; n = n >> 1) {
            if (n & 1) count++; 
        }

        return count;
    }
};