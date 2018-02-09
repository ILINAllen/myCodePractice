class Solution {
public:
    int reverse(int x) {
		
		int flag = 1;
		if(x < 0)flag = -1;
		string temp = to_string(x);
		std::reverse(temp.begin(), temp.end());
		string max = to_string(INT_MAX);
		
		if(temp.size() >= max.size() and temp > max)
		{ return 0;}
		
		return stoi(temp) * flag;
    }
};