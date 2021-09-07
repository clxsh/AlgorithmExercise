class Solution {
public:
    int rob(vector<int>& nums)
    {
        int nsize = nums.size();        
        int a = 0;
        int b = nums[0];
        int c;

        for (int i = 1; i < nsize; ++i) {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }

        return b;
    }
};