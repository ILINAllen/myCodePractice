class Solution {
public:
	string multiply(string num1, string num2) {
		int len1 = num1.size();
		int len2 = num2.size();
		if (len1 == 0 || len2 == 0 || num1 == "0" || num2 == "0") return "0";
		vector<int > temp(len1 + len2 + 1, 0);

		for (int i = 0; i < len1; ++i)
		{
			for (int j = 0; j < len2; ++j)
			{
				temp[i + j + 2] += (num1[i] - '0') * (num2[j] - '0');
			}
		}

		int c = 0;//进位
		for (int i = temp.size() - 1; i >= 0; i--)
		{
			int num = temp[i] + c;
			temp[i] = num % 10;
			c = num / 10;
		}
		int nozeroindex = 0;
		for (; nozeroindex < temp.size(); ++nozeroindex)
		{
			if (temp[nozeroindex] != 0)
				break;
		}

		string res;
		for (int i = nozeroindex; i < temp.size(); ++i)
		{
			res += char(temp[i] + '0');
		}
		return res;
	}
};