class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int max = 0;
		for(int i = 0; i < prices.size(); ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(prices[i] - prices[j] > max)
					max = prices[i] - prices[j];	
			}
		}
		return max;
    }
};