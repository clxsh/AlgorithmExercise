// TLE

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int hsize = height.size();

//         int maxArea = 0;
//         for (int i = 0; i < hsize; ++i) {
//             for (int j = hsize - 1; j > i; --j) {
//                 int hh = min(height[i], height[j]);
//                 maxArea = max(maxArea, hh * (j - i));
//             }
//         }

//         return maxArea;
//     }
// };

class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int hsize = height.size();
        int maxArea = 0;

        int left = 0;
        int right = hsize - 1;

        while (left < right) {
            int leftVal = height[left];
            int rightVal = height[right];
            if (leftVal >= rightVal) {
                maxArea = max(maxArea, rightVal * (right - left));
                --right;
            }
            else {
                maxArea = max(maxArea, leftVal * (right - left));
                ++left;
            }
            
            
        }

        return maxArea;
    }
};