class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0))return false;

		int high = 1;
		int temp = x;
		while (temp/10)
		{
			high *= 10;
			temp /= 10;
		}
		temp = x;
		while (temp)
		{
			if (temp / high != temp % 10)
				return false;
			temp %= high;
			temp /= 10;
			high /= 100;

		}
		return true;
	}
};