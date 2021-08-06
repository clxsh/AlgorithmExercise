class Solution {
private:
    static const int HIGH_BIT = 30;
public:
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;

        for (int i = HIGH_BIT; i >= 0; --i) {
            unordered_set<int> seen;
            // for (int j = 0; j < nums.length(); ++j) {
            //     seen.insert(nums[j] >> i);
            // }
            for (int num : nums) {
                seen.insert(num >> i);
            }

            int next_x = (x << 1) + 1;
            bool found = false;
            for (int num : nums) {
                if (seen.count(next_x ^ (num >> i))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = next_x;
            }
            else {
                x = next_x - 1;
            }
        }

        return x;

    }
};