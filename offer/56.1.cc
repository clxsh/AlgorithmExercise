class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num;
        }

        int div = 1;
        while ((res & div) == 0) {
            div <<= 1;
        }

        int a = 0;
        int b = 0;
        for (auto num : nums) {
            if (num & div)
                a ^= num;
            else
                b ^= num;
        }

        return vector<int>{a, b};
    }
};