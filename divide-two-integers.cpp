class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
		
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long dvd = abs((long)dividend);
		long dsr = abs((long)divisor);
		int res = 0;
		while(dvd >= dsr) {
			
			int factor = 1;
			long tempdsr = dsr;
			while(dvd > tempdsr) {
				if(dvd < (tempdsr << 1)) break;
				
				tempdsr = tempdsr << 1;
				factor = factor << 1;
			}
			dvd -= tempdsr;
			res += factor;	
		}
		return sign > 0 ? res : -res;
    }
};