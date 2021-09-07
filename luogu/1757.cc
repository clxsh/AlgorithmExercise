// 60/100分, Runtime Error

#include <iostream>
#include <vector>
using namespace std;

struct object {
    int weight;
    int value;
    object(int _weight, int _value)
        : weight(_weight), value(_value) {}
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<object>> objects(50, vector<object>());

    for (int i = 0; i < n; ++i) {
        int weight, value, group;
        cin >> weight >> value >> group;
        objects[group].emplace_back(weight, value);
    }

    vector<int> dp(m + 1, 0);

    for (int i = 1; i < objects.size(); ++i) {
        for (int j = m; j >= 0; --j) {
            int osize = objects[i].size();
            for (int k = 0; k < osize; ++k) {
                if (j >= objects[i][k].weight) {
                    dp[j] = max(dp[j], 
                                dp[j - objects[i][k].weight] + objects[i][k].value);
                }
            }
        }
    }

    cout << dp[m] << endl;

    return 0;
}