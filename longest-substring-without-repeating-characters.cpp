class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
		int n = s.length();
		int maxnum, pre = -1;
		map<char, int> strmap;
		
		for(int i = 0; i < n; i++)
		{
			strmap[s[i]] = -1;	
		}
		for(int i = 0; i < n; i++)
		{
			pre = max(pre, strmap[s[i]]);
			maxnum = max(maxnum, i - pre);
			strmap[s[i]] = i;
		}
		return maxnum;
    }
};