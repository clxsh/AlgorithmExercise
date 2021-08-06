#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> res;
    res.reserve(n);
    
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        if (stk.empty() || nums[stk.top()] >= nums[i]) {
            stk.push(i);
        }
        else {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                res[stk.top()] = i + 1;
                stk.pop();
            }
            stk.push(i);
        }
    }

    while (!stk.empty()) {
        res[stk.top()] = 0;
        stk.pop();
    }

    for (int i = 0 ; i < n; ++i)
        cout << res[i] << " ";

    return 0;
}