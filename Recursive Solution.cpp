class Solution {
public:

// Recursive helper function to calculate max profit
// prices  : vector of stock prices by day
// i       : current day index
// have    : whether we currently hold a stock (1 if yes, 0 if no)
// takenat : index at which the stock was bought (valid only if 'have' is 1)
int hlo(vector<int>& prices, int i, int have, int takenat) {
    // Base case: if we've processed all days
    if (i >= prices.size())
        return 0;

    int first = 0, second = 0;

    if (have) {
        // Case 1: Sell the stock today, then cooldown next day (i+2)
        first = prices[i] - prices[takenat] + hlo(prices, i + 2, 0, -1);

        // Case 2: Don't sell today, keep holding the stock
        second = hlo(prices, i + 1, 1, takenat);
    } else {
        // Case 1: Buy the stock today
        first = hlo(prices, i + 1, 1, i);

        // Case 2: Skip today, don't buy
        second = hlo(prices, i + 1, 0, -1);
    }

    // Return the best outcome from the two choices
    return max(first, second);
}

// Main function to start recursion
int maxProfit(vector<int>& prices) {
    return hlo(prices, 0, 0, -1);  // Start from day 0, not holding any stock
}
};
