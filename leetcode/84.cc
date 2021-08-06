class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int hsize = heights.size();
        stack<int> mono_stack;
        vector<int> leftb(hsize);
        vector<int> rightb(hsize, hsize);     // !!! 所有不曾出栈的数字边界默认为最大值

        for (int i = 0; i < hsize; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                rightb[mono_stack.top()] = i;     // 巧妙地优化
                mono_stack.pop();
            }
            leftb[i] = (mono_stack.empty()? -1 : mono_stack.top());
            mono_stack.push(i);
        }
        // rightb[hsize - 1] = hsize;

        int ans = 0;
        for (int i = 0; i < hsize; ++i) {
            ans = max(ans, (rightb[i] - leftb[i] - 1) * heights[i]);
        }

        return ans;
    }
};