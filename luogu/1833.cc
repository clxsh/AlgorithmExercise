#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>
using namespace std;

struct flower {
    int t;
    int c;
    int p;
    flower(int _t, int _c, int _p)
        : t(_t), c(_c), p(_p) {}
};

int main()
{
    int starth, startm;
    int endh, endm;
    int interval;
    int n;
    scanf("%d:%d %d:%d", &starth, &startm, &endh, &endm);
    scanf("%d", &n);
    interval = endh * 60 + endm - starth * 60 - startm;

    vector<shared_ptr<flower>> flowers;
    int t, c, p;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &t, &c, &p);
        if (p == 0 || p == 1) {
            flowers.emplace_back(move(make_shared<flower>(t, c, p)));
        }
        else {
            int s = 1;  // splice
            while (p - s > 0) {
                p -= s;
                flowers.emplace_back(move(make_shared<flower>(t * s, c * s, s)));
                s *= 2;
            }
            if (p != 0)
                flowers.emplace_back(move(make_shared<flower>(t * p, c * p, p)));
        }
    }
    
    vector<int> dp(interval + 1, 0);
    for (int i = 0; i < flowers.size(); ++i) {
        int it = flowers[i]->t;
        int ic = flowers[i]->c;
        if (flowers[i]->p == 0) {
            for (int j = it; j <= interval; ++j) {
                dp[j] = max(dp[j], dp[j - it] + ic);
            }
        }
        else {
            for (int j = interval; j >= it; --j) {
                dp[j] = max(dp[j], dp[j - it] + ic);
            }
        }
    }

    printf("%d\n", dp[interval]);

    return 0;
}