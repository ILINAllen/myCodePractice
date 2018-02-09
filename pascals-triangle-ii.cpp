class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int >res;
		vector<int >cur{ 1, 1 };
		if (rowIndex == 0)return res;
		if (rowIndex == 1)return cur;
		for (int i = 2; i <= rowIndex; ++i)
		{
			
			res.clear();
			res.push_back(1);
			for (int j = 0; j < cur.size() - 1; ++j)
			{
				res.push_back(cur[j] + cur[j + 1]);
			}
			res.push_back(1);
			cur.clear();
			cur.insert(cur.end(), res.begin(), res.end());
		}
		return res;
	}
};