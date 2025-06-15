class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Base case: Only one day, no transaction possible
        if(prices.size() == 1)
            return 0;

        // Base case: Two days, max profit is the positive difference or 0
        if(prices.size() == 2)
            return max(0, prices[1] - prices[0]);

        int n = prices.size();
        vector<int> ans(n, INT_MIN);  // ans[i] stores max profit up to day i

        // Initialize base cases
        ans[0] = 0;  // No profit on the first day
        ans[1] = max(0, prices[1] - prices[0]);  // Max profit from 0→1

        // Iterate through each day from 2 to n-1
        for(int i = 2; i < n; i++) {
            ans[i] = ans[i - 1];  // Option 1: Don't sell on day i

            // Try selling on day i after buying on any day j before it
            for(int j = 0; j <= i - 1; j++) {
                // prices[i] - prices[j]: profit from buying at j and selling at i
                // ans[j-2]: profit before cooldown (skip one day after selling)
                // If j < 2, we can't take ans[j-2], so treat it as 0
                int profit = prices[i] - prices[j] + (j >= 2 ? ans[j - 2] : 0);

                // Update the max profit for day i
                ans[i] = max(ans[i], profit);
            }
        }

        // Return the max profit up to the last day
        return ans[n - 1];
    }
};
