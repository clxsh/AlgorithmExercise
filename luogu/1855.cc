#include <iostream>
#include <vector>
using namespace std;

struct wish {
    int money;
    int time;
};

int main()
{
    int n, M, T;
    cin >> n >> M >> T;
    
    vector<wish> wishes(n);
    for (int i = 0; i < n; ++i) {
        cin >> wishes[i].money >> wishes[i].time;
    }

    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));
    for (int i = 0; i < n; ++i) {
        int money = wishes[i].money;
        int time = wishes[i].time;
        for (int j = M; j >= money; --j) {
            for (int k = T; k >= time; --k) {
                dp[j][k] = max(dp[j][k], dp[j - money][k - time] + 1);
            }
        }
    }

    cout << dp[M][T] << endl;

    return 0;
}