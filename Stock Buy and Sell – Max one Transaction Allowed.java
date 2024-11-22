class Solution {
    public int maximumProfit(int prices[]) {
        // Code here
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        
        int minPrice = Integer.MAX_VALUE;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
            int profit = price - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        
        return maxProfit;
    }
}
