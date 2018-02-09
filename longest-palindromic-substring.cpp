class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		string maxStr;

		vector<int > a;
		vector<vector<int > > b;
		b.resize(len);
		for (int i = 0; i < len; i++)
			b[i].resize(len, 0);

		int max = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (i == j)b[i][j] = 1;
				else if (i - j < 2 && s[i] == s[j])b[i][j] = 1;
				else
				{
					if (i - j >= 2 && b[i - 1][j + 1] && s[i] == s[j])
					{
						b[i][j] = 1;
					}
				}
				if (i - j + 1 > max && b[i][j])
				{
					max = i - j + 1;
					maxStr = s.substr(j, max);
				}
			}
		}
		return maxStr;
	}

};