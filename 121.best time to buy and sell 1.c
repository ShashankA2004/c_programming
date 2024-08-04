

int maxProfit(int prices[], int pricesSize) {
    if (pricesSize == 0) {
        return 0;  // No prices available
    }

    int min_price = INT_MAX;  // Initialize to maximum integer value
    int max_profit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];  // Update min_price if a lower price is found
        }
        int profit = prices[i] - min_price;  // Calculate current profit
        if (profit > max_profit) {
            max_profit = profit;  // Update max_profit if current profit is higher
        }
    }

    return max_profit;
}

