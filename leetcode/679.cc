class Solution {
static constexpr double ref = 1e-6;
private:
    // 注意判别浮点为 0 的方式
    bool isZero(double num)
    {
        return fabs(num) <= ref;
    }

    bool count24(vector<double> &cards, int n)
    {
        if (n == 1) {
            if (isZero(cards[0] - 24))
                return true;
            else
                return false;
        }
        
        vector<double> cards2;
        cards2.reserve(n - 1);

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int m = 0;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        cards2[m] = cards[k];
                        ++m;
                    }
                }
                cards2[m] = cards[i] + cards[j];
                if (count24(cards2, n - 1))
                    return true;

                cards2[m] = cards[i] - cards[j];
                if (count24(cards2, n - 1))
                    return true;
                
                cards2[m] = cards[j] - cards[i];
                if (count24(cards2, n - 1))
                    return true;

                cards2[m] = cards[i] * cards[j];
                if (count24(cards2, n - 1))
                    return true;

                if (!isZero(cards[j])) {
                    cards2[m] = cards[i] / cards[j];
                    if (count24(cards2, n - 1))
                        return true;
                }

                if (!isZero(cards[i])) {
                    cards2[m] = cards[j] / cards[i];
                    if (count24(cards2, n - 1))
                        return true;
                }
            }
        }

        return false;
    }

public:
    bool judgePoint24(vector<int>& cards)
    {
        int size = cards.size();
        vector<double> cards2;
        cards2.reserve(size);

        for (int i = 0; i < size; ++i) {
            cards2[i] = cards[i];
        }

        return count24(cards2, size);
    }
};