class Solution {
private:
    int median(int &left, int &mid, int &right)
    {
        if ((left <= mid && mid <= right) || (right <= mid && mid <= left))
            swap(left, mid);
        else if ((left <= right && right <= mid) || (mid <= right && right <= left))
            swap(left, right);

        return left;
    }
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int mid = (right - left) / 2 + left;
        int pivot = median(nums[left], nums[mid], nums[right]);
        int i = left;
        int j = right;

        while (i < j) {
            while (i < j && nums[j] >= pivot)
                --j;
            while (i < j && nums[i] <= pivot)
                ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right); 
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int nsize = nums.size();
        quickSort(nums, 0, nsize - 1);

        vector<vector<int>> res;

        int third;
        for (int first = 0; first < nsize; ++first) {
            third = nsize - 1;
            if (first != 0 && nums[first - 1] == nums[first])
                continue;

            for (int second = first + 1; second < nsize; ++second) {
                if (second != first + 1 && nums[second - 1] == nums[second])
                    continue;

                while (third > second && nums[first] + nums[second] + nums[third] > 0)
                    --third;
                if (third == second)
                    break;

                if (nums[first] + nums[second] + nums[third] == 0)
                    res.push_back(vector<int>{nums[first], nums[second], nums[third]});
            }
        }

        return res;
    }
};