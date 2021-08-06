#include <iostream>
#include <vector>

using namespace std;

struct charm {
    int weight;
    int desir;
    charm(int _weight, int _desir)
        : weight(_weight), desir(_desir) {}
};

int pack(vector<charm> &charms, int n, int m)
{
    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= charms[i].weight; --j) {
            dp[j] = max(dp[j], dp[j - charms[i].weight] + charms[i].desir);
        }
    }

    return dp[m];
}

int main(int argc, char *argv[])
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<charm> charms;
    charms.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> charms[i].weight >> charms[i].desir;
    }

    cout << pack(charms, n, m) << endl;

    return 0;
}