class Solution {
public:
    // bubble sort
    // vector<int> sortArray(vector<int>& nums)
    // {
    //     int size = nums.size();

    //     for (int i = 0; i < size; ++i) {
    //         for (int j = 0; j < size - i - 1; ++j) {
    //             if (nums[j] > nums[j+1]) {
    //                 swap(nums[j], nums[j+1]);
    //             }
    //         }
    //     }

    //     return nums;
    // }

    // insertion sort
    // vector<int> sortArray(vector<int> &nums)
    // {
    //     int size = nums.size();

    //     for (int i = 0; i < size; ++i) {
    //         int key = nums[i];
    //         int j = i - 1;
    //         while (j >= 0 && nums[j] > key) {
    //             nums[j+1] = nums[j];
    //             --j;
    //         }
    //         nums[j+1] = key;
    //     }

    //     return nums;
    // }

    // merge sort
    // void merge(vector<int> &nums, int start, int mid, int end, vector<int> &tmp)
    // {
    //     int i = start;
    //     int j = mid + 1;
    //     int index = start;

    //     while (i <= mid && j <= end) {
    //         if (nums[i] < nums[j]) {
    //             tmp[index] = nums[i];
    //             ++i;
    //         }
    //         else {
    //             tmp[index] = nums[j];
    //             ++j;
    //         }
    //         ++index;
    //     }

    //     while (i <= mid) {
    //         tmp[index] = nums[i];
    //         ++index;
    //         ++i;
    //     }

    //     while (j <= end) {
    //         tmp[index] = nums[j];
    //         ++index;
    //         ++j;
    //     }

    //     copy(tmp.begin() + start, tmp.begin() + end + 1, nums.begin() + start);
    // }

    // void mergeSort(vector<int> &nums, int start, int end, vector<int> &tmp)
    // {
    //     if (start < end) {
    //         int mid = start + (end - start) / 2;
    //         mergeSort(nums, start, mid, tmp);
    //         mergeSort(nums, mid+1, end, tmp);
    //         merge(nums, start, mid, end, tmp);
    //     }

    //     return;
    // }

    // vector<int> sortArray(vector<int> &nums)
    // {
    //     int size = nums.size();
    //     vector<int> tmp(size + 1);

    //     mergeSort(nums, 0, size - 1, tmp);

    //     return nums;
    // }

    // quick sort
    int median(int &left, int &mid, int &right)
    {
        if ((left >= mid && mid >= right) || (right >= mid && mid >= left)) {
            swap(left, mid);
        }
        else if ((left >= right && right >= mid) || (mid >= right && right >= left)) {
            swap(left, right);
        }

        return left;
    }

    void quickSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;

        int pivot = median(nums[start], nums[(start+end)/2], nums[end]);

        int i = start;
        int j = end;
        while (i != j) {
            while (i < j && nums[j] >= pivot) {
                --j;
            }
            while (i < j && nums[i] <= pivot) {
                ++i;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[start], nums[i]);

        quickSort(nums, start, i - 1);
        quickSort(nums, i + 1, end);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }
};

class Solution {
private:
    void heapSort(vector<int> &nums)
    {
        int size = nums.size();
        heapify(nums);

        for (int i = size - 1; i >= 0; ) {
            swap(nums[0], nums[i]);
            --i;
            siftDown(nums, 0, i);
        }
    }

    void heapify(vector<int> &nums)
    {
        int size = nums.size();

        for (int i = (size - 1) / 2; i >= 0; --i) {
            siftDown(nums, i, size - 1);
        }
    }

    void siftDown(vector<int> &nums, int k, int end)
    {
        while (2 * k + 1 <= end) {
            int j = 2 * k + 1;
            if (j + 1 <= end && nums[j+1] > nums[j])
                ++j;
            if (nums[k] < nums[j])
                swap(nums[k], nums[j]);
            else
                break;
            k = j;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);

        return nums;
    }
};

