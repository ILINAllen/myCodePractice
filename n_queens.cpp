class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
	
		vector<vector<string> > res;
		vector<int> vec(n, 0); //第i行皇后，放在第vec[i]列
		
		search(res, vec, n, 0);
		return res;
    }
	
	void search(vector<vector<string> > &res, vector<int> &vec, int n, int cur)
	{
		if(cur >= n)
		{
			vector<string> temp;
			for(int i = 0; i < n; ++i)
			{
				string str;
				for(int j = 0; j < n; ++j)
				{
					if(vec[i] == j)
						str += "Q";
					else
						str += ".";
				}
				temp.push_back(str);
			}
			res.push_back(temp);
			return;
		}
		
		//遍历 当前 cur 行 皇后处于每一列的情况	
		for(int i = 0; i < n; ++i)
		{
			vec[cur] = i;  
			int ok = 1;
			for(int j = 0; j < cur; ++j)
			{
				if(vec[j] == vec[cur] || vec[j] + j == vec[cur] + cur || vec[j] - j == vec[cur] - cur)
				{
					ok = 0;
					break;
				}
			}
			if(ok)
				search(res, vec, n, cur + 1);
		}
		
	}
};