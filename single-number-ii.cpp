class Solution {
public:
    int singleNumber(int A[], int n) {
		
		if(A == NULL or n <= 0)
		map<int, int> m;
		for(int i = 0; i < n; ++i)
		{
			m[A[i]]++; 
		}
		for(auto iter = m.begin(); iter != m.end(); ++iter)
		{
			if((*iter).second = 1)
				return (*iter).first;
			
		}
		return 0;
		
		
		
    }
};