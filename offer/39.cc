class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int votes = 0;
        for (int num : nums) {
            if (votes == 0)
                res = num;
            if (num == res) {
                votes += 1;
            }
            else {
                votes -= 1;
            }
        }

        return res;
    }
};