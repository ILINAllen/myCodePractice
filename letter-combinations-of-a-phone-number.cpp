class Solution {
public:

	vector<string> dict{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
 
		vector<string> res;
		DFS(res, "", digits, 0);
		return res;
    }
	
	void DFS(vector<string> & res, string temp, string &digits, int index) {
		
		if(temp.size() > digits.size() || index > digits.size()) {
			return;
		}
		
		if(temp.size() == digits.size() && index == digits.size()) {
			res.push_back(temp);
			return;
		}
			
		
		for(int i = index; i < digits.size(); ++i) {
			
			for(int j = 0; j < dict[digits[i] - '0' - 1].size(); ++j) {	
				DFS(res, temp + char(dict[digits[i] - '0' - 1][j]), digits, i + 1);
			}
		}		
	}
	
	
};