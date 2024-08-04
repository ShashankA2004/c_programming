

int maxProfit(int prices[], int pricesSize) {
    if (pricesSize <= 1) {
        return 0;  // Not enough days to make any transactions
    }

    int total_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // If today's price is higher than yesterday's price, add the difference to the profit
        if (prices[i] > prices[i - 1]) {
            total_profit += prices[i] - prices[i - 1];
        }
    }

    return total_profit;
}

