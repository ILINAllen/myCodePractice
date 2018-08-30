class Solution {
public:
    double pow(double x, int n) {
		
		if(n < 0) return 1/power(x, -n);
		return power(x, n);
    
    }
	
	
	double power(double x, int n)
	{
		if(n == 0) return 1;
		double temp = power(x, n / 2);
		if(n % 2) 
			return temp * temp * x;  //奇数
		else 
			return temp * temp;
	}
	
};