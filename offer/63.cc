class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int minPrice = prices[0];
        int maxP = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // if (prices[i] <= minPrice) {
            //     minPrice = prices[i];
            // }
            // else {
            //     maxP = max(prices[i] - minPrice, maxP);
            // }
            minPrice = min(minPrice, prices[i]);
            maxP = max(prices[i] - minPrice, maxP);
        }

        return maxP;
    }
};