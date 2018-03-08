class Solution {
public:
	int longestConsecutive(vector<int> &num) {

		sort(num.begin(), num.end());

		int max = 1, count = 1;
		for (int i = 0; i < num.size() - 1; ++i)
		{
			if (num[i + 1] == num[i] + 1)
				count++;
			else if (num[i + 1] == num[i])
				continue;
			else
			{
				if (count > max)
				{
					max = count;
				}
				count = 1;
			}
		}
		if (count > max)
		{
			max = count;
		}
		return max;
	}
};