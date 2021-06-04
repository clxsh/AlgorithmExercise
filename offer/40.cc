
// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         vector<int> res;

//         int size = arr.size();
//         for (int i = 0; i < k; ++i) {
//             int index = i;
//             for (int j = index + 1; j < size; ++j) {
//                 if (arr[j] < arr[index])
//                     index = j;
//             }
//             swap(arr[index], arr[i]);
//             res.push_back(arr[i]);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int> &arr, int k)
//     {
//         int arrsize = arr.size();
//         vector<int> res(k, 0);
//         if (k == 0) {
//             return res;
//         }
//         priority_queue<int> q;
//         for (int i = 0; i < k; ++i) {
//             q.push(arr[i]);
//         }

//         for (int i = k; i < arrsize; ++i) {
//             if (q.top() > arr[i]) {
//                 q.pop();
//                 q.push(arr[i]);
//             }
//         }

//         for (int i = 0; i < k; ++i) {
//             res[i] = q.top();
//             q.pop();
//         }

//         return res;

//     }
// };

class Solution {
private:
    int partition(vector<int> &arr, int left, int right)
    {
        int pivot = arr[right];
        int toswap = left - 1;

        for (int i = left; i <= right - 1; ++i) {
            if (arr[i] <= pivot) {
                toswap = toswap + 1;
                swap(arr[toswap], arr[i]);
            }
        }
        swap(arr[toswap + 1], arr[right]);

        return (toswap + 1);
    }

    int randomized_partition(vector<int> &arr, int left, int right)
    {
        int random = rand() % (right - left + 1) + left;
        swap(arr[random], arr[right]);

        return partition(arr, left, right);
    }

    void randomized_selected(vector<int> &arr, int left, int right, int k)
    {
        if (left >= right)
            return;

        int pos = randomized_partition(arr, left, right);
        int num = pos - left + 1;
        if (num == k)
            return;
        else if (num > k) {
            randomized_selected(arr, left, pos - 1, k);
        }
        else {
            randomized_selected(arr, pos + 1, right, k - num);
        }
    }

public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, arr.size() - 1, k);

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }

        return res;
    }
};