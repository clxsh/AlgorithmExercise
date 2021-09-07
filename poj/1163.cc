#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int len = i + 1;
        for (int j = 0; j < len; ++j) {
            cin >> triangle[i][j];
        }
    }

    int base = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        int len = i + 1;
        for (int j = 0; j < len; ++j) {
            triangle[base][j] = max(triangle[base][j], triangle[base][j + 1])
                                + triangle[i][j];
        }
    }
    
    cout << triangle[base][0] << endl;

    return 0;
}