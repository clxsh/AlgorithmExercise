class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0;
        for (; i < 5; ++i) {
            if (nums[i] == 0)
                count++;
            else
                break;
        }

        bool res = true;
        int pre;
        if (i < 5) {
            pre = nums[i];
            ++i;
        }
        else {
            return res;
        }
        while (i < 5) {
            if (i > 0 && nums[i] == pre + 1) {
                pre = nums[i];
                ++i;
            }
            else if (count) {
                count--;
                pre += 1;
            }
            else {
                res = false;
                break;
            }
        }

        return res;
    }
};