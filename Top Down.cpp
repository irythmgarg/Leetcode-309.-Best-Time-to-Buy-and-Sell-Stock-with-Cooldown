class Solution {
public:
int dp[5001][2];  // dp[i][have]: Max profit on day i with state 'have' (1 if holding stock, 0 if not)

// Recursive helper function to calculate max profit
// i     : current day
// have  : whether we are currently holding a stock (1 = yes, 0 = no)
int hlo(vector<int>& prices, int i, int have)
{
    // Base case: if all days are processed
    if(i >= prices.size())
        return 0;

    // Return memoized result if already computed
    if(dp[i][have] != -1)
        return dp[i][have];

    int first = 0, second = 0;

    if(have) {
        // Case 1: Sell the stock today and apply cooldown (skip next day)
        first = prices[i] + hlo(prices, i + 2, 0);

        // Case 2: Hold the stock, skip to the next day
        second = hlo(prices, i + 1, 1);
    } else {
        // Case 1: Buy the stock today (reduce profit)
        first = -prices[i] + hlo(prices, i + 1, 1);

        // Case 2: Skip buying today
        second = hlo(prices, i + 1, 0);
    }

    // Memoize and return the maximum profit for this state
    return dp[i][have] = max(first, second);
}

// Main function that initializes dp and starts the recursion
int maxProfit(vector<int>& prices) {
    memset(dp, -1, sizeof(dp));  // Initialize all dp values to -1
    return hlo(prices, 0, 0);    // Start from day 0 with no stock in hand
}
};
