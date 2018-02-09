class Solution {
public:
	void dp(vector<vector<int> > &triangle, int dpindex, int i, int sum, int &min)
	{
		if (dpindex >= triangle.size())
		{
			if (sum < min)
				min = sum;
			return;
		}
		for (int j = 0; j < 2; ++j)
		{
			if (triangle[dpindex].size() <= i + j)
				continue;
			sum += triangle[dpindex][i + j];
			dp(triangle, dpindex + 1, i + j, sum, min);
			sum -= triangle[dpindex][i + j];
		}
	}

	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() < 1)return 0;
		int min = 999999999;
		dp(triangle, 0, 0, 0, min);
		return min;
	}
};