class Solution {
public:
	int partProfit(vector<int> &prices, int i, int j)
	{
		int maxd = -99999;

		for (int k = i; k <= j - 1; ++k)
		{
			for (int l = k + 1; l <= j; l++)
				maxd = max(maxd, prices[l] - prices[k]);
		}
		return maxd > 0 ? maxd : 0;
	}

	int maxProfit(vector<int> &prices) {
		if(prices.size() == 0 or prices.size() == 1)
			return 0;
		if(prices.size() == 2)
			return max(0, prices[1] - prices[0]);

		int res = -99999;
		for (int i = 0; i < prices.size() - 1; ++i)
		{
			res = max(res, partProfit(prices, 0, i) + partProfit(prices, i + 1, prices.size() - 1));
		}

		res = max(res, partProfit(prices, 0, prices.size() - 1));
		return res;
	}
	
};