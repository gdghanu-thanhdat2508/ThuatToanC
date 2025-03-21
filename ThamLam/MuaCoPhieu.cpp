void MuaCoPhieu()
{
    // Mô tả bài toán: bạn được cung cấp một mảng giá của một cố phiếu trong một số ngày.
    // Bạn phải chọn ra một ngày để mua cổ phiếu và một ngày khác để bán cổ phiếu đó.
    // Kết quả trả về là lợi nhuận mà bạn kiếm được.
    int n = 6;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // for storing best days to buy and sell stock
    pair<int, int> ans;
    // For storing maximum profit
    int maxProfit = 0;
    // For storing minimum purchase of stock
    int minBuy = INT_MAX;
    // index of minbuy
    int ind;

    for (int i = 0; i < prices.size(); i++)
    {

        // if we get min price for buying than earlier then we update minBuy and its index
        if (minBuy > prices[i])
        {
            ind = i;
            minBuy = prices[i];
        }

        // Finding maximum profit by checking selling at ith day prices with minBuy
        if (maxProfit < prices[i] - minBuy)
        {
            maxProfit = prices[i] - minBuy;
            ans = {ind, i}; // storing the days of buying and selling
        }
    }

    // Printing the best time to buy and sell stock and its maximum profit
    cout << "Best Time to buy on day " << ans.first + 1 << " and sell on day " << ans.second + 1 << endl;
    cout << "Maximum Profit Will be " << maxProfit;
    // Best Time to buy on day 2 and sell on day 5.
    // Maximum Profit Will be 5
}