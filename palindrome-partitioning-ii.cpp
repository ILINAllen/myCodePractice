class Solution {
public:
    int minCut(string s) {
        int len = s.size();
		int *d = new int[len + 1];
		
		for(int i = 0; i < s.size(); ++i)
			d[i] = i;
		for(int i = 0; i < s.size(); ++i)
		{
			if(ispalindrome(s, 0 ,i))
				d[i] = 0;
			if(d[i] == 0)continue;
			
			for(int j = 1; j <= i; j++)
			{
				if(ispalindrome(s, j , i))
					d[i] = min(d[i], d[j - 1] + 1);
				else
					d[i] = min(d[i], d[j - 1] + i + 1 - j);
				
			}
		}	
		return d[len - 1];
    }
	
	bool ispalindrome(string s, int left, int right)
	{
		for(int i = left, j = right; i < j; ++i, --j)
		{
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
};