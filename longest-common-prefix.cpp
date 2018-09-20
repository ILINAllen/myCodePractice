class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		if(strs.size() <= 0) return "";
		sort(strs.begin(), strs.end());
		int minlen = strs[0].size();
		
		int j = 0;
		for(j = 0; j < minlen; ++j) {
			int ok = 1;
			for(int i = 0; i < strs.size() - 1; ++i) {
				if(strs[i][j] != strs[i + 1][j]) {
					ok = 0;
					break;
				}		
			}
			if(!ok)
				break;
		}
		return strs[0].substr(0, j);
    }
};