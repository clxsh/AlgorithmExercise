#include <iostream>
#include <vector>
using namespace std;

struct herb {
    int time;
    int value;
};

int main()
{
    int t;
    int m;
    cin >> t >> m;

    vector<herb> herbs(m);
    for (int i = 0; i < m; ++i) {
        cin >> herbs[i].time >> herbs[i].value;
    }

    vector<uint64_t> dp(t + 1);          // uint64_t to prevent overflow
    for (int i = 0; i < m; ++i) {
        for (int j = herbs[i].time; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - herbs[i].time] + herbs[i].value);
        }
    }

    cout << dp[t] << endl;

    return 0;
}