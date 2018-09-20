class Solution {
public:
    void nextPermutation(vector<int> &num) {
		
		int n = num.size();
		int i = n - 2, j = n - 1;
		
		while(i >= 0 && num[i] >= num[i + 1]) 
			i--;
		
		if(i == -1) {
			reverse(num.begin(), num.end());
		}
		else {
			while(j >= 0 && num[i] >= num[j]) j--;
			swap(num[i], num[j]);
			reverse(num.begin() + i + 1, num.end());
		}
    }
};