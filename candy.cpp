class Solution {
public:
    int candy(vector<int> &ratings) {
		
		int len = ratings.size();
		if(len == 0) return 0;
		if(len == 1) return 1;

		vector<int> vec(len, 1);
		
		for(int i = 1; i < len; ++i)
		{
			if(ratings[i] > ratings[i - 1])
				vec[i] = vec[i - 1] + 1;
		}
		
		for(int i = len - 2; i >= 0; --i)
		{
			if(ratings[i] > ratings[i + 1] and v[i] <= v[i + 1])
				vec[i] = vec[i + 1] + 1;
		}
		
		int sum = 0;
		
		for(int i = 0; i < len; ++i)
		{
			sum += vec[i];
		}
		
		return sum;
    }
};