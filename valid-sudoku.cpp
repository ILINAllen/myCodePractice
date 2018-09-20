class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		
		if(board.size() <= 0) 
			return false;
		return solve(board, 0);
    }
	
	bool solve(vector<vector<char> > &board, int num) {
		
		if(num >= 81)
			return true;
		
		int m = num / 9;
		int n = num % 9;
		
		if(board[m][n] != '.') {
			if(isValid(board, m, n, board[m][n]))	{
				if(solve(board, num + 1))
					return true;
			}
		}
		else{
			if(solve(board, num + 1))
				return true;
		}
		return false;
	}
	
	bool isValid(vector<vector<char> > &board, int m, int n, char c) {
		
		int tempm = m / 3;
		int tempn = n / 3;
		int beginm = tempm * 3;
		int beginn = tempn * 3;
		
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(beginm + i == m && beginn + j == n)
					continue;
				if(board[beginm + i][beginn + j] == c)
					return false;
			}
		}
			
		for(int i = 0; i < 9; ++i) {
			if(board[m][i] == c && i != n)
				return false;
			if(board[i][n] == c && i != m)
				return false;			
		}
		return true;
	}
};