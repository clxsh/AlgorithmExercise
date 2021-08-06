// Time Limit Exceeded ...

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    // min
    deque<int> mq;
    int i, j = 0;
    for (i = 0; i < k; ++i) {
        while (!mq.empty() && mq.back() > nums[i]) {
            mq.pop_back();
        }
        mq.push_back(nums[i]);
    }
    cout << mq.front() << " ";
    for (;  i < n; ++i) {
        if (mq.front() == nums[j]) {
            mq.pop_front();
        }
        ++j;

        while (!mq.empty() && mq.back() > nums[i]) {
            mq.pop_back();
        }
        mq.push_back(nums[i]);
        cout << mq.front() << " ";
    }
    cout << endl;
    mq.clear();

    // max
    for (i = 0; i < k; ++i) {
        while (!mq.empty() && mq.back() < nums[i])
            mq.pop_back();
        mq.push_back(nums[i]);
    }
    cout << mq.front() << " ";
    for (j = 0; i < n; ++i) {
        if (mq.front() == nums[j])
            mq.pop_front();
        ++j;

        while (!mq.empty() && mq.back() < nums[i])
            mq.pop_back();
        mq.push_back(nums[i]);
        cout << mq.front() << " ";
    }

    return 0;
}