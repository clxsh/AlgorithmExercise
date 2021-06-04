class Solution {
public:
/*
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < numbers.size(); ++i) {
            auto it = hashmap.find(target - numbers[i]);
            if (it != hashmap.end()) {
                return {it->second + 1, i + 1};
            }
            hashmap[numbers[i]] = i;
        }
        return {};

    }
*/

/*
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int left = i + 1;
            int right = numbers.size() - 1;
            int target2 = target - numbers[i];
            while (left < right) {\
                int mid = left + (right - left) / 2;
                if (numbers[mid] > target2) right = mid;
                else if (numbers[mid] < target2) left = mid + 1;
                else return {i + 1, mid + 1};
            }
            if (numbers[left] == target2) {
                return {i + 1, left + 1};
            }
        }

        return {};
    }
*/
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] < target) ++left;
            else if (numbers[left] + numbers[right] > target) --right;
            else return {left + 1, right + 1};
        }

        return {};
    }
};