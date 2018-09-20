class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
    
		if(board.size() <= 0)
			return;
		solve(board, 0); 
    }
	
	bool solve(vector<vector<char> > &board, int num)
	{
		if(num >= 81)
			return true;
		
		int m = num / 9;
		int n = num % 9;
		//有值的时候
		if(board[m][n] != '.') {
			if(solve(board, num + 1)) {
				return true;
			}
			return false;
		}
		else {		
		//无值的时候
			for(int i = '1'; i <= '9'; ++i)
			{
				if(isvalid(board, m, n, char(i)))
				{
					board[m][n] = char(i);
					if(solve(board, num + 1))
						return true;
					board[m][n] = '.';
				}
			}	
		}
		return false;
	}
	
	bool isvalid(vector<vector<char> > &board, int m, int n, char c) {
		
		int tempm = m / 3;
		int tempn = n / 3;
		int mbegin = tempm * 3;
		int nbegin = tempn * 3;
		
		// 读小的九宫格
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; j++) {
				
				if(board[mbegin + i][nbegin + j] == c)
					return false;
			}
		}
		
		// 读一行或一列
		for(int i = 0; i < 9; i++)
		{
			if(board[m][i] == c || board[i][n] == c)
				return false;
		}
		return true;
	}
	
};