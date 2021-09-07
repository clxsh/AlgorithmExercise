class Solution {
private:
    int findKNum(vector<int> &nums1, int left1, vector<int> &nums2, int left2, int k)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();

        if (left1 >= size1)
            return nums2[left2 + k - 1];
        if (left2 >= size2)
            return nums1[left1 + k - 1];

        if (k == 1)
            return min(nums1[left1], nums2[left2]);

        int t1 = (left1 + k / 2 - 1 < size1) ? nums1[left1 + k / 2 - 1] : INT_MAX;
        int t2 = (left2 + k / 2 - 1 < size2) ? nums2[left2 + k / 2 - 1] : INT_MAX;
        if (t1 < t2) {
            return findKNum(nums1, left1 + k / 2, nums2, left2, k - k / 2);
        }
        else{
            return findKNum(nums1, left1, nums2, left2 + k / 2, k - k / 2);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int nsize1 = nums1.size();
        int nsize2 = nums2.size();
        int size = nsize1 + nsize2;
        int k1 = (size + 1) / 2;
        int k2 = (size + 2) / 2;

        if (size & 1) {
            return findKNum(nums1, 0, nums2, 0, k1);
        }
        else {
            return (findKNum(nums1, 0, nums2, 0, k1) + findKNum(nums1, 0, nums2, 0, k2)) / 2.0;
        }
    }
};