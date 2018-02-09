class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if (numRows == 0)
			return res;
		
		vector<int> cur{1};
		res.push_back(cur);
		if (numRows == 1)
			return res;

		for (int i = 1; i < numRows; ++i)
		{
			cur.clear();
			cur.push_back(1);
			for (int j = 0; j < res[i - 1].size() - 1 && res[i - 1].size() > 1; ++j)
			{
				cur.push_back(res[i - 1][j] + res[i - 1][j + 1]);
			}
			cur.push_back(1);

			res.push_back(cur);
		}
		return res;
	}
};